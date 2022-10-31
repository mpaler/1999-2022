<?php

class SwaylocksSurfshopSurfcraftMigration extends SwaylocksMigration {
    /**
 * @file
 */
  public function __construct() {
    parent::__construct();

    // Give this migration a description.
    $this->description = t('Migrate D5 Surfshop.');

    // Grab the source user data from the D6 table, but not for the superuser.
    $query = $this
      ->getConnection()
      ->select($this->source_db_name.'.node', 'n')
      ->fields('n', array('uid', 'vid', 'nid', 'title', 'created', 'changed', 'status', 'comment', 'promote', 'moderate', 'sticky'))
 	  ->condition('n.type', 'surfshop_surfcraft');

    //GET Content type fields
	$tables = array('content_type_surfshop_surfcraft', 'content_field_manufacturer','content_field_price', 'content_field_price_note', 'content_field_surfshop_payment_methods', 'content_field_location', 'content_field_description', 'content_field_image_1');
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

    $query->addJoin('LEFT OUTER', $this->source_db_name.'.files', 'f',  'content_field_image_1.field_image_1_fid = f.fid');
    $query->fields('f', array('filepath'));
/*
    $this->highwaterField = array(
    		'name' => 'changed',
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
    $this->source = new MigrateSourceSQL($query, $source_fields, NULL, array('map_joinable' => FALSE));

    // Set up the destination object.
    // We're importing passwords that have already been converted to md5.
    $this->destination = new MigrateDestinationNode('surfshop_surfcraft');

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

     $this->addFieldMapping('field_description', 'field_description_value');
     $this->addFieldMapping('field_description:format')->defaultValue('filtered_html');



     //$this->addFieldMapping('field_image_1', 'field_image_1_title');
     $this->addFieldMapping('field_image_1', 'filepath');
     $this->addFieldMapping('field_image_1:source_dir')
     ->defaultValue('http://www.swaylocks.com');

     $this->addFieldMapping('field_image_1:destination_dir')
     ->defaultValue('public://');

     $this->addFieldMapping('field_image_1:file_replace')
     ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

     $this->addFieldmapping('field_image_1:preserve_files')
     ->defaultValue(TRUE);



     $this->addFieldMapping('field_dimensions', 'field_dimensions_value');
     $this->addFieldMapping('field_surfshop_qty', 'field_surfshop_qty_value');
     $this->addFieldMapping('field_surfshop_ship_handling_co', 'field_surfshop_ship_handling_co_value');
     $this->addFieldMapping('field_surfshop_shit_cost_per', 'field_surfshop_shit_cost_per_value');
     $this->addFieldMapping('field_surfhop_ship_to_location', 'field_surfshop_ship_to_location_value');
     $this->addFieldMapping('field_surfshop_shipping_notes', 'field_surfshop_shipping_notes_value');
     $this->addFieldMapping('field_surfshop_return_period', 'field_surfshop_return_period_value');

     $this->addFieldMapping('field_surfshop_return_policy', 'field_surfshop_return_policy_value');
     $this->addFieldMapping('field_surfshop_return_type', 'field_surfshop_return_type_value');
     $this->addFieldMapping('field_surfshop_payment_notes', 'field_surfshop_payment_notes_value');
     $this->addFieldMapping('field_surfshop_refund_notes', 'field_surfshop_refund_notes_value');

     $this->addFieldMapping('field_price', 'field_price_value');
     $this->addFieldMapping('field_price_note', 'field_price_note_value');
     $this->addFieldMapping('field_surfshop_payment_methods', 'field_surfshop_payment_methods_value');


     $this->addFieldMapping('field_surfcraft_length', 'field_surfcraft_length')
     ->defaultValue('')
     ->description(t('See Prepare row'));
     $this->addFieldMapping('field_surfcraft_length:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_design_fin_setup', 'field_design_fin_setup')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_design_fin_setup:source_type')->defaultValue('tid');

    // :source_type')->defaultValue('tid');

     $this->addFieldMapping('field_material_core', 'field_material_core')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_material_core:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_material_laminate', 'field_material_laminate')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_material_laminate:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_material_sealer', 'field_material_sealer')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_material_sealer:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_year', 'field_year')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_year:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_shaper','field_shaper')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_shaper:source_type')->defaultValue('tid');

     $this->addFieldMapping('field_manufacturer', 'field_manufacturer_value')
      ->defaultValue('')
      ->description(t('See Prepare row'));
     $this->addFieldMapping('field_manufacturer:source_type')->defaultValue('tid');


    // $this->addFieldMapping('field_manufacturer_value', 'field_manufacturer_value');
     $this->addFieldMapping('field_model_name','field_model_name')
     ->defaultValue('')
      ->description(t('See Prepare row'));


     $this->addFieldMapping('field_surfshop_location', 'field_location_value');

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



  	$vocabStruct = array(
  			'7' => 'field_surfcraft_length', //Design: Length

  			'8' => 'field_shaper', //Shaper

  			'9' =>  'field_manufacturer',//Manufacturer

  			'10' =>  'field_year',//Year Built

  			'11' => 'field_model_name', //Model Name

  			'21' => 'field_material_core',  //Materials: Core

  			'22' => 'field_material_sealer',  //Materials: Resin/Sealer

  			'23' => 'field_material_laminate',  //Materials: Laminate

  			'24' => 'field_design_fin_setup', //Design: Fin Setup
  			/*
  			 '39' => array( //location

  			 '41' => array( //Profile: Industry Status

  			 '42' => array( //People: Shapers

  			'43' => array( //People: Surfers

  			'44' => array( //Profile: Specialties/Interests
  			 										*/
  	);




  	$query = $this->getConnection()->select('term_node', 'tn')
  	->fields('tn', array('tid'));
  	$query->condition('nid', $row->nid);
  	$query->addJoin('LEFT OUTER', $this->source_db_name.'.term_data', 'td',  'tn.tid = td.tid');
  	$query->fields('td', array('name', 'description', 'vid'));
  	$results = $query->execute();
  	foreach($results as $result){
  		if(isset($vocabStruct[$result->vid])){
  			$row->{$vocabStruct[$result->vid]} = $result->tid;
  		}
  	}




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
  public function prepare($obj, $row) {
  	return TRUE;

  }

}




class SwaylocksSurfshopNonSurfcraftMigration extends SwaylocksMigration {
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
 	  ->condition('n.type', 'surfshop_non_surfcraft');

    //GET Content type fields
	$tables = array('content_type_surfshop_non_surfcraft');
	foreach($tables as $table){
		$query->addJoin('LEFT OUTER', $this->source_db_name.'.'.$table, $table,  $table.' = n.nid');
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
    $this->destination = new MigrateDestinationNode('surfshop_non_surfcraft');

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
     $this->addFieldMapping('body:format', 'format');


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
