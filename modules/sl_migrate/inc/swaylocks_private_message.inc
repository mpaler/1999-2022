<?php

class SwaylocksPrivateMessageMigration extends SwaylocksMigration {
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
      ->select($this->source_db_name.'.privatemsg', 'pm')
      ->fields('pm', array('id', 'author', 'recipient', 'subject', 'message', 'timestamp', 'newmsg', 'hostname', 'folder', 'author_del', 'recipient_del', 'format', 'thread', 'type', 'variables'));





    // By passing an array of source fields to the MigrateSourceSQL constructor,
    // we can modify the descriptions of source fields (which just default, for
    // SQL migrations, to table_alias.column_name), as well as add additional fields
    // which may be populated in prepareRow().
    $source_fields = array();

    // Set up the source object.
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    // Set up the destination object.
    // We're importing passwords that have already been converted to md5.
    $this->destination = new MigrateDestinationPrivateMsg();

   $this->map = new MigrateSQLMap($this->machineName,
         array(
           'id' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE)
         ),
         MigrateDestinationPrivateMsg::getKeySchema()
       );

       $this->addFieldMapping('subject', 'subject');
       $this->addFieldMapping('body', 'message');
       $this->addFieldMapping('format', 'format');
       $this->addFieldMapping('recipients', 'recipient')
         ->sourceMigration('SwaylocksUser');
       $this->addFieldMapping('timestamp', 'timestamp');
       $this->addFieldMapping('author', 'author')
          ->sourceMigration('SwaylocksUser');
       $this->addFieldMapping('is_new', 'newmsg')->defaultValue(1);

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