<?php

class SwaylocksSwaylopediaBookMigration extends SwaylocksMigration {
    /**
 * @file
 *   This is the migration for Users.
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D5 books.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.node', 'n')
      ->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
 	  ->condition('n.type', 'book');

    //GET Content type fields
	$tables = array('content_type_book');
	foreach($tables as $table){
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.'.$table, $table,  $table.'.nid = n.nid');
		$columns = array();
		$result = $this->getConnection()->query('DESCRIBE '.$this->source_db_name.'.'.$table);
		foreach($result as $row){
			$columns[] = $row->Field;
		}
		$query->fields($table, $columns);
	}

    //GET BODY\
    $query->addJoin('LEFT OUTER', $this->source_db_name.'.node_revisions', 'nr',  'nr.nid = n.nid');
    $query->fields('nr', array('title', 'body', 'teaser', 'format'));




    // By passing an array of source fields to the MigrateSourceSQL constructor,
    // we can modify the descriptions of source fields (which just default, for
    // SQL migrations, to table_alias.column_name), as well as add additional fields
    // which may be populated in prepareRow().
    $source_fields = array();

    // Set up the source object.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    // Set up the destination object.
    // We're importing passwords that have already been converted to md5.
    $this->destination = new MigrateDestinationNode('book');

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


     $this->addFieldMapping('body', 'body');
     $this->addFieldMapping('body:summary', 'teaser');
     $this->addFieldMapping('body:format')
     ->defaultValue('advanced_editor');

     $this->addFieldMapping('field_swaylopedia_category','field_swaylopedia_category')
     ->defaultValue('')
     ->description(t('See Prepare row'));

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

    $query = $this->getConnection()->select('term_node', 'tn')
    ->fields('tn', array('tid'));
    $query->condition('nid', $row->nid);
    $query->addJoin('LEFT OUTER', $this->source_db_name.'.term_data', 'td',  'tn.tid = td.tid');
    $query->fields('td', array('name', 'description', 'vid'));
    $results = $query->execute();
    foreach($results as $result){
    	if(isset($this->vocabStruct[$result->vid])){
    		$row->{$this->vocabStruct[$result->vid]} = $result->tid;
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


class SwaylocksSwaylopediaImageMigration extends SwaylocksMigration {
	/**
	 * @file
	 */
	public function __construct() {
		parent::__construct();

		// Give this migration a description.
		$this->description = t('Migrate D5 swaylopedia images.');

		// Grab the source user data from the D6 table, but not for the superuser.
		$query = $this
		->getConnection()
		->select($this->source_db_name.'.node', 'n')
		->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
		->condition('n.type', 'image')
				->orderBy('created', 'DESC');

/*
		//GET Content type fields
		$tables = array('content_type_image', 'content_field_image_1', 'content_field_description');
		foreach($tables as $table){
			$query->addJoin('LEFT OUTER', $table, $table,  $table.'.vid = n.vid');
			$columns = array();
			$result = $this->getConnection()->query('DESCRIBE '.$this->source_db_name.'.'.$table);
			foreach($result as $row){
				$columns[] = $row->Field;
			}
			$query->fields($table, $columns);
		}
*/


		//GET BODY\
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.node_revisions', 'nr',  'nr.nid = n.nid');
		$query->fields('nr', array('title', 'body', 'teaser', 'format'));

		//$query->addJoin('LEFT OUTER', $this->source_db_name.'.content_field_image_1', 'cfi1',  'cfi1.nid = n.nid');
		//$query->fields('cfi1', array('field_image_1_fid'));

		$query->addJoin('LEFT OUTER', $this->source_db_name.'.image', 'i',  'i.nid = n.nid');
		$query->condition('i.image_size', '_original');;

		$query->fields('i', array('fid'));

		$query->addJoin('LEFT OUTER', $this->source_db_name.'.files', 'f',  'i.fid = f.fid');
		$query->fields('f', array('filepath'));


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
		$this->destination = new MigrateDestinationNode('image');

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


		//$this->addFieldMapping('field_image_1', 'field_image_1_title');
		$this->addFieldMapping('field_image', 'filepath');
		$this->addFieldMapping('field_image:source_dir')
		->defaultValue('http://www.swaylocks.com');

		$this->addFieldMapping('field_image:destination_dir')
		->defaultValue('public://');

		$this->addFieldMapping('field_image:destination_file', 'filepath');

		$this->addFieldMapping('field_image:file_replace')
		->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

		$this->addFieldmapping('field_image:preserve_files')
		->defaultValue(TRUE);



		$this->addFieldMapping('body', 'body');
		$this->addFieldMapping('body:summary', 'teaser');
		$this->addFieldMapping('body:format')
		->defaultValue('advanced_editor');

		$this->addFieldMapping('field_swaylopedia_category','field_swaylopedia_category')
		->defaultValue('')
		->description(t('See Prepare row'));

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

		$query = $this->getConnection()->select('term_node', 'tn')
		->fields('tn', array('tid'));
		$query->condition('nid', $row->nid);
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.term_data', 'td',  'tn.tid = td.tid');
		$query->fields('td', array('name', 'description', 'vid'));
		$results = $query->execute();
		foreach($results as $result){
			//dsm($result);
			if(isset($this->vocabStruct[$result->vid])){
				$row->{$this->vocabStruct[$result->vid]} = $result->tid;
			}
		}




		// Add the path to the source row, if relevant

		$path = $this->getPath('node/' . $row->nid);
		if ($path) {
			$row->path = $path;
		}

		if (parent::prepareRow($row) === FALSE) {
			return FALSE;
		}
		return TRUE;
	}


	/**
	 * Called after the imported entity is created.
	 */
	public function prepare($obj, $current_row) {
		return TRUE;
	}

}



class SwaylocksSwaylopediaGlossaryMigration extends SwaylocksMigration {
	/**
	 * @file
	 */
	public function __construct() {
		parent::__construct();

		// Give this migration a description.
		$this->description = t('Migrate D5 glossary.');

		// Grab the source user data from the D6 table, but not for the superuser.
		$query = $this
		->getConnection()
		->select($this->source_db_name.'.node', 'n')
		->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
		->condition('n.type', 'glossary');

		//GET Content type fields
		$tables = array('content_type_glossary');
		foreach($tables as $table){
			$query->addJoin('LEFT OUTER', $this->source_db_name.'.'.$table, $table,  $table.'.nid = n.nid');
			$columns = array();
			$result = $this->getConnection()->query('DESCRIBE '.$this->source_db_name.'.'.$table);
			foreach($result as $row){
				$columns[] = $row->Field;
			}
			$query->fields($table, $columns);
		}

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
		$this->destination = new MigrateDestinationNode('glossary');

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


		$this->addFieldMapping('body', 'body');
		$this->addFieldMapping('body:summary', 'teaser');
		$this->addFieldMapping('body:format')
		->defaultValue('advanced_editor');

		$this->addFieldMapping('field_swaylopedia_category','field_swaylopedia_category')
		->defaultValue('')
		->description(t('See Prepare row'));

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


		$query = $this->getConnection()->select('term_node', 'tn')
		->fields('tn', array('tid'));
		$query->condition('nid', $row->nid);
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.term_data', 'td',  'tn.tid = td.tid');
		$query->fields('td', array('name', 'description', 'vid'));
		$results = $query->execute();
		foreach($results as $result){
			if(isset($this->vocabStruct[$result->vid])){
				$row->{$this->vocabStruct[$result->vid]} = $result->tid;
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
