<?php

class SwaylocksUserMigration extends SwaylocksMigration {
    /**
 * @file
 *   This is the migration for Users.
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D5 users.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.users', 'u')
      ->fields('u', array('uid', 'name', 'pass', 'mail', 'created', 'access', 'login', 'status', 'init', 'timezone', 'picture'))
  //    $query->addJoin('LEFT OUTER', $this->source_db_name.'.content_type_profile', 'p',  'n.nid = p.nid');
	  ->condition('u.uid', 0, '>');

    $query->orderBy('u.uid', 'ASC');

    // By passing an array of source fields to the MigrateSourceSQL constructor,
    // we can modify the descriptions of source fields (which just default, for
    // SQL migrations, to table_alias.column_name), as well as add additional fields
    // which may be populated in prepareRow().
    $source_fields = array();

    // Set up the source object.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    // Set up the destination object.
    // We're importing passwords that have already been converted to md5.
    $this->destination = new MigrateDestinationUser(array('md5_passwords' => TRUE));

    // Identify the value in the source that maps to the key in the destination.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D7 UID',
          'alias' => 'users',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    // Map our destination and source fields.

    // Simple mapping where the source and destination fields are the same.
    $this->addSimpleMappings(array('uuid', 'pass', 'created', 'access', 'login', 'status', 'init'));

    // Adding 'is_new' means we want to preserve the original uid in the destination.
    //$this->addFieldMapping('is_new')->defaultValue(TRUE); Keeps the original UID - which we don't want,

    $this->addFieldMapping('name', 'name')->dedupe('users', 'name');
    $this->addFieldMapping('mail', 'mail')->dedupe('users', 'mail');
    $this->addFieldMapping('language')->defaultValue('');
    $this->addFieldMapping('theme')->defaultValue('');
    $this->addFieldMapping('signature')->defaultValue('');
    $this->addFieldMapping('signature_format')->defaultValue('advanced_editor');
    $this->addFieldMapping('timezone', 'timezone')->defaultValue(NULL);

     $this->addFieldMapping('picture', 'd7_file_id')
      ->defaultValue('')
      ->description(t('See Prepare row'));


//map first name
//     $this->addFieldMapping('field_user_first_name', 'field_user_first_name')
//     ->defaultValue('')
//      ->description(t('See Prepare row'));

//map last name
//     $this->addFieldMapping('field_user_last_name', 'field_user_last_name')
//      ->defaultValue('')
//      ->description(t('See Prepare row'));
//map full name
//     $this->addFieldMapping('field_user_full_name', 'field_user_full_name')
//      ->defaultValue('')
//      ->description(t('See Prepare row'));



    // We map either role ids or role names, not both. We choose to map role ids
    // and retrieve the right values in prepare().
    $this->addFieldMapping('roles')->description('Handled in prepare');
    $this->addFieldMapping('role_names')->issueGroup(t('DNM'));

    // @TODO What do we really want to do with path aliases on migration??
    $this->addFieldMapping('path')->issueGroup(t('DNM'))->description('Handled in prepareRow');
    $this->addFieldMapping('pathauto')->defaultValue(0);
  }


  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with fields.
   */
  public function prepareRow($row) {

    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

//ATTACHED MIGRATED FILES
	    $query = db_select('.file_managed', 'f')
	    ->fields('f', array('fid'))
	    ->condition('uri', 'public://'.$this->cleanUri($row->picture));
		$result = $query->execute();
		//dsm($row->picture);
		//dsm($row);
	    foreach ($result as $resultRow) {
	    	//dsm($resultRow);
	    	$row->d7_file_id = $resultRow->fid;
		}




//ADD firstname and last name fields + deprecated full name

	/*
    $query = $this->getConnection()->select('node', 'n')
      ->fields('n', array('title'));
	$query->condition('uid', $row->uid);
	$query->condition('type', 'profile');
	$results = $query->execute();
	foreach($results as $result){
		$name_parser = new NameParser;
		$name = $name_parser->split_full_name($result->title);
		$row->field_user_full_name	= $result->title;
		$row->field_user_first_name	= (strlen($name['fname']) > 0) ? $name['fname'] : 'NA';
		$row->field_user_last_name	= (strlen($name['lname']) > 0) ? $name['lname'] : 'NA';
	}
	if(!$name){
		$row->field_user_first_name	= $row->mail;
		$row->field_user_last_name	= $row->name;
	}
*/


    // Translate the format
    // Add the path to the source row, if relevant
//    if (module_exists('path')) {
//      $path = $this->get_url_alias('user', $row->uid);
//      if ($path) {
//        $row->path = $path;
//      }
//    }
    return TRUE;
  }


  /**
   * Called after the imported entity is created.
   */
  public function prepare($account, $current_row) {


    // Add an array of user roles to the imported user.
    // User role names rather than role ids in case the ids are different in the source.

/*
  	$source_id = $account->uuid;
    $query = $this->getConnection()->select('users_roles', 'ur')
      ->fields('ur', array('uid', 'rid'));
    $query->join('role', 'r', 'r.rid=ur.rid');
    $query->fields('r', array('name'));
	$query->join('uuid_users', 'uuid', 'uuid.uid=ur.uid');
	$query->condition('uuid.uuid', $source_id, '=');
    $results = $query->execute();



    // Migrate module does something like this if we supply an array of role names.
    // But it happens too early in the processing for us to use it.
    // It's just as easy to do it ourselves in prepare().
    $account->roles = array();
    foreach ($results as $row) {
    //dsm($row);
	  $role_name = $row->name;
      $role = user_role_load_by_name($role_name);
      if ($role) {
        $account->roles[$role->rid] = $role->rid;
      }
    }
*/
    // We could also have used this function to decide to skip a row, in cases
    // where that couldn't easily be done through the original query. Simply
    // return FALSE in such cases.
    return TRUE;

  }

 // path needs to be stripped
  protected function cleanUri($uri) {
    return str_replace('files/', '', $uri);
  }

}




//HANDLE USER IMAGE MIGRATION


class SwaylocksUserImageMigration extends SwaylocksMigration {
    /**
 * @file
 *   This is the migration for Users.
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D6 user images.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.users', 'u')
      ->fields('u', array('uid', 'name', 'pass', 'mail', 'created', 'access', 'login', 'status', 'init', 'timezone', 'picture'))
  //    $query->addJoin('LEFT OUTER', $this->source_db_name.'.content_type_profile', 'p',  'n.nid = p.nid');
	  ->condition('u.uid', 1, '>');

    $this->highwaterField = array(
    		'name' => 'access',
    		'alias' => 'u',
    		'type' => 'int',
    );
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
        'uid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D7 UID',
          'alias' => 'u',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    // Map our destination and source fields.



     $this->addFieldMapping('uid', 'uid')->sourceMigration('SwaylocksUser');

	 $this->addFieldMapping('timestamp', 'created');

	 $this->addFieldMapping('source_dir')
     ->defaultValue('http://swaylocks.com/');

	 $this->addFieldMapping('destination_dir')
         ->defaultValue('public://');

	 $this->addFieldMapping('value', 'picture');

	 $this->addFieldMapping('destination_file', 'picture')
	   ->callbacks(array($this, 'cleanUri'));


     $this->addFieldMapping('file_replace')
	 ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

	 $this->addFieldmapping('preserve_files')
	 ->defaultValue(TRUE);

  }


 // path needs to be stripped
  protected function cleanUri($uri) {
  	//dsm($uri);
  	return str_replace('files/', '', $uri);
  }


 public function prepare($obj, $current_row) {
 	//dsm($obj);
	//dsm($current_row);
 }
}




class SwaylocksProfileMigration extends SwaylocksMigration {
	/**
	 * @file
	 *   This is the migration for Users Profiles.
	 */
	public function __construct() {
		parent::__construct();

		// Give this migration a description.
		$this->description = t('Migrate D6 user profiles.');


		// Grab the source user data from the D6 table, but not for the superuser.
		$query = $this
		->getConnection()
		->select($this->source_db_name.'.users', 'u')
		->fields('u', array('uid', 'access'))
		->condition('u.uid', 0, '>');
		//JOIN NODE TABLE
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.node', 'n',  'n.uid = u.uid');
		$query->fields('n', array('nid', 'title'));
		$query->condition('n.type', 'bio');

		//JOIN CONTENT TYPE PROFILE TABLE FIELDS
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.content_type_bio', 'b',  'n.nid = b.nid');


		$columns = array();
		$result = $this->getConnection()->query('DESCRIBE '.$this->source_db_name.'.content_type_bio');
		foreach($result as $row){
			$columns[] = $row->Field;
		}

		$query->fields('b', $columns);

		$query->orderBy('u.uid', 'ASC');

/*
		$this->highwaterField = array(
				'name' => 'access',
				'alias' => 'u',
				'type' => 'int',
		);
*/
		// By passing an array of source fields to the MigrateSourceSQL constructor,
		// we can modify the descriptions of source fields (which just default, for
		// SQL migrations, to table_alias.column_name), as well as add additional fields
		// which may be populated in prepareRow().
		$source_fields = array();

		// Set up the source object.
		$this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

		//TODO ABOVE

		//Dependency fails unless full migration of dependency class completes
		//$this->dependencies = array('SwaylocksUser');
		// profile2-"Profile type"
		$this->destination = new MigrateDestinationProfile2('main');

		// Identify the value in the source that maps to the key in the destination.
		$this->map = new MigrateSQLMap($this->machineName,
				array(
						'uid' => array(
								'type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'D7 uid',
						),
				),
				MigrateDestinationProfile2::getKeySchema()
		);

		// Map our destination and source fields.

		$this->addFieldMapping('uid', 'uid')
		->sourceMigration('SwaylocksUser');


		$this->addFieldMapping('field_user_bio', 'field_about_me_value');
		$this->addFieldMapping('field_user_bio:format', 'field_bio_quiver_format')
		 ->defaultValue('advanced_editor');

		$this->addFieldMapping('field_user_board_count', 'field_bio_boards_made_value');
		$this->addFieldMapping('field_user_quiver', 'field_bio_quiver_value');
		$this->addFieldMapping('field_user_quiver:format', 'field_bio_quiver_format')
		 ->defaultValue('advanced_editor');

		$this->addFieldMapping('field_user_first_board', 'field_bio_first_board_value');

		$this->addFieldMapping('field_user_occupation', 'field_occupation_0_value');

		$this->addFieldMapping('field_bio_years_surfing', 'field_bio_years_surfing_value');

		$this->addFieldMapping('field_shaping_since', 'field_shaping_since_value');

		$this->addFieldMapping('field_name', 'field_name_value');

		$this->addFieldMapping('field_bio_favorite_links', 'field_bio_favorite_links_links');
		$this->addFieldMapping('field_bio_favorite_links:title', 'field_bio_favorite_links_titles');

		$this->addFieldMapping('field_location_taxonomize_terms', 'field_location_taxonomize_terms');
		$this->addFieldMapping('field_location_taxonomize_terms:source_type')->defaultValue('tid');

		$this->addFieldMapping('field_bio_favorite_surfers', 'field_bio_favorite_surfers');
		$this->addFieldMapping('field_bio_favorite_surfers:source_type')->defaultValue('tid');

		$this->addFieldMapping('field_bio_industry_status', 'field_bio_industry_status');
		$this->addFieldMapping('field_bio_industry_status:source_type')->defaultValue('tid');

		$this->addFieldMapping('field_bio_shaping_interests', 'field_bio_shaping_interests');
		$this->addFieldMapping('field_bio_shaping_interests:source_type')->defaultValue('tid');

		$this->addFieldMapping('field_bio_influences', 'field_bio_influences');
		$this->addFieldMapping('field_bio_influences:source_type')->defaultValue('tid');

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


		$query = $this->getConnection()->select('content_field_bio_favorite_links', 'bl')
		->fields('bl', array('field_bio_favorite_links_url', 'field_bio_favorite_links_title'));
		$query->condition('nid', $row->nid);
		$results = $query->execute();
		$bioLinks = array();
		foreach($results as $result){
			if((isset($result->field_bio_favorite_links_url)) && (strlen($result->field_bio_favorite_links_url) > 0)){
				//dsm($result);
				$bioLinksLinks[] = $result->field_bio_favorite_links_url;
				$bioLinksTitles[] = $result->field_bio_favorite_links_title;
			}
		}

		$row->field_bio_favorite_links_links = $bioLinksLinks;
		$row->field_bio_favorite_links_title = $bioLinksTitles;
	}
	public function prepare($obj, $current_row) {

	}
}
