<?php

/**
 * @file
 *   This is a place to define things that are shared between various migration classes.
 */

abstract class SwaylocksMigration extends Migration {







  public function __construct() {
    parent::__construct();
    $this->team = array(
      new MigrateTeamMember('Eric Hildebrand', 'eric@blackantelope.com', t('developer')),
    );
    $this->source_connection_id =  variable_get('sl_migrate_source_connection', 'swaylocks_d6');
    $this->source_path = variable_get('swaylocksd6_source_path');

	$this->source_db_name = variable_get('sl_migrate_source_db_name');






	$this->vocabStruct = array(
			'7' => 'field_surfcraft_length', //Design: Length

			'8' => 'field_shaper', //Shaper

			'9' =>  'field_manufacturer',//Manufacturer

			'10' =>  'field_year',//Year Built

			'11' => 'field_model_name', //Model Name

			'20' => 'field_swaylopedia_category',

			'21' => 'field_material_core',  //Materials: Core

			'22' => 'field_material_sealer',  //Materials: Resin/Sealer

			'23' => 'field_material_laminate',  //Materials: Laminate

			'24' => 'field_design_fin_setup', //Design: Fin Setup

            '39' => 'field_design_fin_setup', //location

            '41' => 'field_bio_industry_status', //Profile: Industry Status
		    '42' => 'field_bio_shaping_interests', //People: Shapers
			'43' => 'field_bio_favorite_surfers', //People: Surfers
            '44' => 'field_bio_influences' //Profile: Specialties/Interests


	);


  }

  function getConnection() {
    return Database::getConnection('default', $this->source_connection_id);
  }

  /**
   * Map between D6 input format id and D7 text format name.
   */

  public function get_source_text_formats() {
     return array(
       1 => 'filtered_html',
       2 => 'full_html',
       3 => 'php_code',
       4 => 'full_html',
       5 => 'full_html',
    );
  }

  public function getPath($source) {
  	$path =  $this
      ->getConnection()
  		->select('url_alias', 'ua')
  		->fields('ua', array('dst'))
  		->condition('src', $source)
  		->execute()
  		->fetchField();

  	return $path;
  }

}
