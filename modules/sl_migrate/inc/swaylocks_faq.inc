<?php

class SwaylocksFAQMigration extends SwaylocksMigration {
    /**
 * @file
 *   This is the migration for Users.
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D5 FAQ.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.node', 'n')
      ->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
 	  ->condition('n.type', 'faq');

    //GET Content type fields
	$tables = array('content_type_faq');
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
    $this->destination = new MigrateDestinationNode('faq');

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