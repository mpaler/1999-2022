<?php

class SwaylocksForumMigration extends SwaylocksMigration {
    /**
 * @file
 *   This is the migration for Users.
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D5 forums.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.node', 'n')
      ->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
  //    $query->addJoin('LEFT OUTER', $this->source_db_name.'.content_type_profile', 'p',  'n.nid = p.nid');
	  ->condition('n.type', 'forum');

    //GET FORUM
    $query->addJoin('LEFT OUTER', $this->source_db_name.'.forum', 'forum',  'forum.nid = n.nid');
    $query->fields('forum', array('tid'));

    //GET BODY\
    $query->addJoin('LEFT OUTER', $this->source_db_name.'.node_revisions', 'nr',  'nr.nid = n.nid');
    $query->fields('nr', array('title', 'body', 'teaser', 'format'));

    $this->highwaterField = array(
    		'name' => 'changed',
    		'alias' => 'n',
    		'type' => 'int',
    );


    // By passing an array of source fields to the MigrateSourceSQL constructor,
    // we can modify the descriptions of source fields (which just default, for
    // SQL migrations, to table_alias.column_name), as well as add additional fields
    // which may be populated in prepareRow().
    $source_fields = array();

    // Set up the source object.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    // Set up the destination object.
    // We're importing passwords that have already been converted to md5.
    $this->destination = new MigrateDestinationNode('forum');

    // Identify the value in the source that maps to the key in the destination.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D5 nid',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Map our destination and source fields.

    // Simple mapping where the source and destination fields are the same.
    $this->addSimpleMappings(array('title', 'created', 'changed', 'comment', 'status', 'sticky', 'promote'));

    // Adding 'is_new' means we want to preserve the original uid in the destination.
    //$this->addFieldMapping('is_new')->defaultValue(TRUE); Keeps the original UID - which we don't want,

     $this->addFieldMapping('uid', 'uid')
         ->sourceMigration('SwaylocksUser');



     $this->addFieldMapping('taxonomy_forums', 'tid');
     $this->addFieldMapping('taxonomy_forums:source_type')
     ->defaultValue('tid');
  //   $this->addFieldMapping('taxonomy_forums:source_type', 'tid');


     $this->addFieldMapping('body', 'body');
     $this->addFieldMapping('body:summary', 'teaser');
     $this->addFieldMapping('body:format')
     ->defaultValue('advanced_editor');

     /*
     $this->addFieldMapping('field_file_attachments', 'd7_file_ids')
     ->description(t('See Prepare row'));

     $this->addFieldMapping('field_file_attachments:file_class')
     ->defaultValue('MigrateFileFid');
     */

     $this->addFieldMapping('field_file_attachments', 'd7_file_names');
     $this->addFieldMapping('field_file_attachments:source_dir')
     ->defaultValue('http://swaylocks.com');

     if (module_exists('path')) {
     	$this->addFieldMapping('path', 'path')
     	->description('Handled in prepareRow');
     }

     if (module_exists('pathauto')) {
     	$this->addFieldMapping('pathauto')
     	->description('By default, disable in favor of migrated paths')
     	->defaultValue(0);
     }


  }


  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with fields.
   */
  public function prepareRow($row) {

    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }


    $row->d7_file_ids = array();
    if(isset($row->nid)){
    	$query = $this->getConnection()->select('files', 'f')
    	->fields('f', array('filename', 'filepath'));
    	$query->condition('nid', $row->nid);
    	$results = $query->execute();
    	foreach($results as $result){

    		$row->d7_file_names[] = $result->filepath;

    		/*
    		$query = db_select('.file_managed', 'f')
    		->fields('f', array('fid'))
    		->condition('uri', 'public://'.str_replace('files/', '',$result->filepath));
    		$result = $query->execute();

    		foreach ($result as $resultRow) {

    			$row->d7_file_ids[] = $resultRow->fid;
    		}
			*/

    	}
    }


    // Add the path to the source row, if relevant

    	$path = $this->getPath('node/' . $row->nid);
    	if ($path) {
    		$row->path = $path;
    	}


    return TRUE;
  }


  /**
   * Called after the imported entity is created.
   */
  public function prepare($account, $current_row) {
  	    return TRUE;

  }

}



class SwaylocksCommentMigration extends SwaylocksMigration {
	/**
	 * @file
	 *   This is the migration for Users.
	 */
	public function __construct() {
		parent::__construct();

		// Give this migration a description.
		$this->description = t('Migrate D5 comments.');

		$source_fields = array();


		// Grab the source user data from the D6 table, but not for the superuser.
		$query = $this
		->getConnection()
		->select($this->source_db_name.'.comments', 'c');;
		$query->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject', 'comment', 'hostname', 'timestamp', 'score', 'status', 'format', 'thread', 'users', 'name', 'mail', 'homepage'));

		$query->addJoin('INNER', $this->source_db_name.'.node', 'n',  'n.nid = c.nid');
		$query->condition('n.type', 'forum')
		->orderBy('timestamp', 'DESC');

		$this->highwaterField = array(
				'name' => 'timestamp',
				'alias' => 'c',
				'type' => 'int',
		);

		// Set up the source object.
		$this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

		$this->destination = new MigrateDestinationComment('comment_node_forum');

		$this->map = new MigrateSQLMap($this->machineName,
				array(
						'cid' => array('type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'Source comment ID',
			//					'alias' => 'c',
						),
				),
				MigrateDestinationComment::getKeySchema()
		);



		/**
		 * Setup common mappings.
		 */
		$this->addSimpleMappings(array('pid', 'subject',
				'hostname', 'thread', 'name', 'mail', 'homepage'));



		// Version-specific field mappings
		$this->addFieldMapping('comment_body', 'comment');
		$this->addFieldMapping('comment_body:format')
		->defaultValue('advanced_editor');

		$this->addFieldMapping('created', 'timestamp');
		$this->addFieldMapping('changed', 'timestamp');

			$this->addFieldMapping('nid', 'nid')
			->sourceMigration('SwaylocksForum');

			$this->addFieldMapping('uid', 'uid')
			->sourceMigration('SwaylocksUser');

			/*
			$this->addFieldMapping('field_images', 'd7_file_ids')
			->sourceMigration('SwaylocksCommentImage')
			->description(t('See Prepare row'));

			$this->addFieldMapping('field_images:file_class')
			->defaultValue('MigrateFileFid');
*/
			//$this->addFieldMapping('field_file_attachments', 'd7_file_names')
			//->description(t('See Prepare row'));

			$this->addFieldMapping('field_file_attachments', 'd7_file_names');
			$this->addFieldMapping('field_file_attachments:source_dir')
				 ->defaultValue('http://swaylocks.com');
			$this->addFieldMapping('field_file_attachments:file_replace')->defaultValue(FILE_EXISTS_REPLACE);
			$this->addFieldMapping('field_file_attachments:preserve_files')->defaultValue(TRUE);

		/*
			$this->addFieldMapping('field_file_attachments:file_class')
			->defaultValue('MigrateFileFid');
*/

	}


	public function prepareRow($row) {

		//	dsm($current_row);
		//	dsm($obj);
		$row->d7_file_ids = array();
		$row->d7_file_names = array();

		if(isset($row->cid)){
			$query = $this->getConnection()->select('comment_upload_files', 'cf')
			->fields('cf', array('filename', 'filepath'));
			$query->condition('cid', $row->cid);
			$results = $query->execute();
			foreach($results as $result){

				$row->d7_file_names[] = $result->filepath;

				/*
				$query = db_select('.file_managed', 'f')
				->fields('f', array('fid'))
				->condition('uri', 'public://'.str_replace('files/', '',$result->filepath));
				$result = $query->execute();
				//dsm($row->picture);
				//dsm($row);
				foreach ($result as $resultRow) {
					//dsm($resultRow);
					$row->d7_file_ids[] = $resultRow->fid;
				}
				*/

			}
			dsm($row->d7_file_ids);
		}
	}

	public function complete($obj, $current_row) {

		dsm($obj);


	}


}





class SwaylocksCommentImageMigration extends SwaylocksMigration {
	/**
	 * @file
	 *   This is the migration for Users.
	 */
	public function __construct() {
		parent::__construct();

		// Give this migration a description.
		$this->description = t('Migrate D6 comment images.');

		// Grab the source user data from the D6 table, but not for the superuser.
		$query = $this
		->getConnection()
		->select($this->source_db_name.'.comment_upload_files', 'cf')
		->fields('cf', array('fid','nid','cid','filename','filepath','filemime','filesize','description','list'))
		->orderBy('cid', 'DESC');

		/*
		$query->addJoin('LEFT INNER', $this->source_db_name.'.comments', 'c',  'c.cid = cf.cid');
		$query->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject', 'comment', 'hostname', 'timestamp', 'score', 'status', 'format', 'thread', 'users', 'name', 'mail', 'homepage'));
*/
		/*
		$this->highwaterField = array(
				'name' => 'timestamp',
				'alias' => 'n',
				'type' => 'int',
		);
*/
		// By passing an array of source fields to the MigrateSourceSQL constructor,
		// we can modify the descriptions of source fields (which just default, for
		// SQL migrations, to table_alias.column_name), as well as add additional fields
		// which may be populated in prepareRow().
		$source_fields = array();

		// Set up the source object.
		$this->source = new MigrateSourceSQL($query);

		$this->destination = new MigrateDestinationFile();

		// Identify the value in the source that maps to the key in the destination.
		$this->map = new MigrateSQLMap($this->machineName,
				array(
						'cid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'd5 cid',
								'alias' => 'cf',
						),
				),
					MigrateDestinationComment::getKeySchema()
		);

		// Map our destination and source fields.



		$this->addFieldMapping('uid', 'uid')
		->sourceMigration('SwaylocksUser');

	 $this->addFieldMapping('timestamp', 'created');

	 $this->addFieldMapping('source_dir')
	 ->defaultValue('http://swaylocks.com');

	 $this->addFieldMapping('destination_dir')
	 ->defaultValue('public://');

	 $this->addFieldMapping('value', 'filepath');

	 $this->addFieldMapping('destination_file', 'filepath')
	   ->callbacks(array($this, 'cleanUri'));

	 $this->addFieldMapping('file_replace')
	 ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

	 $this->addFieldmapping('preserve_files')
	 ->defaultValue(TRUE);

	}


	// path needs to be stripped
	protected function cleanUri($uri) {
		return str_replace('files/', '', $uri);
	}


	public function prepare($obj, $current_row) {
	//	dsm($current_row);
	//	dsm($obj);
	}
	public function complete($obj, $current_row) {
	//	dsm($current_row);
	//	dsm($obj);
	}

}

