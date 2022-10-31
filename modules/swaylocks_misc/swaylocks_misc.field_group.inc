<?php
/**
 * @file
 * swaylocks_misc.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function swaylocks_misc_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|profile2|main|default';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_websites',
      1 => 'field_user_occupation',
      2 => 'field_user_bio',
      3 => 'field_name',
      4 => 'field_bio_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'classes' => ' group-about field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_about|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about|profile2|main|form';
  $field_group->group_name = 'group_about';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_user_websites',
      1 => 'field_user_occupation',
      2 => 'field_user_bio',
      3 => 'field_name',
      4 => 'field_bio_location',
      5 => 'field_proifle_signature',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_about|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_groups|user|user|form';
  $field_group->group_name = 'group_account_groups';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '5',
    'children' => array(
      0 => 'og_user_node',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-groups field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_account_groups|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_notify_settings|user|user|form';
  $field_group->group_name = 'group_account_notify_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Settings',
    'weight' => '2',
    'children' => array(
      0 => 'message_subscribe_email_freq',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-notify-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_account_notify_settings|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_pm_settings|user|user|form';
  $field_group->group_name = 'group_account_pm_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Private Message Settings',
    'weight' => '3',
    'children' => array(
      0 => 'privatemsg',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-pm-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_account_pm_settings|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_signature|user|user|form';
  $field_group->group_name = 'group_account_signature';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signature & Avatar',
    'weight' => '4',
    'children' => array(
      0 => 'picture',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-signature field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_account_signature|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account_un_pw|user|user|form';
  $field_group->group_name = 'group_account_un_pw';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Username & Password',
    'weight' => '1',
    'children' => array(
      0 => 'account',
      1 => 'timezone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-account-un-pw field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_account_un_pw|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buyer_payment_methods|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_buyer_payment_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buyer payment methods',
    'weight' => '5',
    'children' => array(
      0 => 'field_surfshop_payment_notes',
      1 => 'field_payment_methods',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Buyer payment methods',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-buyer-payment-methods field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_buyer_payment_methods|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_design_construction|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_design_construction';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Design & construction',
    'weight' => '2',
    'children' => array(
      0 => 'field_dimensions',
      1 => 'field_surfcraft_length',
      2 => 'field_design_fin_setup',
      3 => 'field_material_core',
      4 => 'field_material_laminate',
      5 => 'field_material_sealer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Design & construction',
      'instance_settings' => array(
        'classes' => ' group-design-construction field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_design_construction|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_design|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_design';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Design & construction',
    'weight' => '2',
    'children' => array(
      0 => 'field_dimensions',
      1 => 'field_surfcraft_length',
      2 => 'field_design_fin_setup',
      3 => 'field_material_core',
      4 => 'field_material_laminate',
      5 => 'field_material_sealer',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Design & construction',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-design field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_design|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|surfshop_non_surfcraft|default';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_image_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-images field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_images|node|surfshop_non_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|surfshop_non_surfcraft|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '2',
    'children' => array(
      0 => 'field_image_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-images field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_images|node|surfshop_non_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '8',
    'children' => array(
      0 => 'field_image_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-images field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_images|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_non_sc_pricing_qty|node|surfshop_non_surfcraft|default';
  $field_group->group_name = 'group_non_sc_pricing_qty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing & Quantity',
    'weight' => '1',
    'children' => array(
      0 => 'field_price',
      1 => 'field_price_note',
      2 => 'field_surfshop_qty',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pricing & Quantity',
      'instance_settings' => array(
        'classes' => 'group-non-sc-pricing-qty field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_non_sc_pricing_qty|node|surfshop_non_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_non_sc_pricing_qty|node|surfshop_non_surfcraft|form';
  $field_group->group_name = 'group_non_sc_pricing_qty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing & Quantity',
    'weight' => '1',
    'children' => array(
      0 => 'field_price',
      1 => 'field_price_note',
      2 => 'field_surfshop_qty',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pricing & Quantity',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-non-sc-pricing-qty field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_non_sc_pricing_qty|node|surfshop_non_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_payment_methods|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_payment_methods';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buyer payment methods',
    'weight' => '4',
    'children' => array(
      0 => 'field_surfshop_payment_notes',
      1 => 'field_payment_methods',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Buyer payment methods',
      'instance_settings' => array(
        'classes' => ' group-payment-methods field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_payment_methods|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_information|node|surfshop_non_surfcraft|default';
  $field_group->group_name = 'group_photo_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_photoarchive_non_surfcraf',
      1 => 'field_item_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Item Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-photo-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_information|node|surfshop_non_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_information|node|surfshop_non_surfcraft|form';
  $field_group->group_name = 'group_photo_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_non_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Item Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_photoarchive_non_surfcraf',
      1 => 'title_field',
      2 => 'field_item_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Item Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-photo-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_information|node|surfshop_non_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_information|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_photo_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shaper Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_year',
      1 => 'field_shaper',
      2 => 'field_manufacturer',
      3 => 'field_model_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shaper Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-photo-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_photo_information|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pricing_and_qty|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_pricing_and_qty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing & Quantity',
    'weight' => '1',
    'children' => array(
      0 => 'field_price',
      1 => 'field_price_note',
      2 => 'field_surfshop_qty',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pricing & Quantity',
      'instance_settings' => array(
        'classes' => ' group-pricing-and-qty field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pricing_and_qty|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pricing_information|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_pricing_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing & Quantity',
    'weight' => '4',
    'children' => array(
      0 => 'field_price',
      1 => 'field_price_note',
      2 => 'field_surfshop_qty',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pricing & Quantity',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-pricing-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_pricing_information|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_return_policy|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_return_policy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Return policy',
    'weight' => '7',
    'children' => array(
      0 => 'field_surfshop_refund_notes',
      1 => 'field_surfshop_refund_type',
      2 => 'field_surfshop_return_policy',
      3 => 'field_surfshop_return_within',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Return policy',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-return-policy field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_return_policy|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_returns|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_returns';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Return/Refund Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_surfshop_refund_notes',
      1 => 'field_surfshop_refund_type',
      2 => 'field_surfshop_return_policy',
      3 => 'field_surfshop_return_within',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Return/Refund Information',
      'instance_settings' => array(
        'classes' => 'group-returns field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_returns|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shaper_info|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_shaper_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shaper Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_year',
      1 => 'field_shaper',
      2 => 'field_manufacturer',
      3 => 'field_model_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shaper Information',
      'instance_settings' => array(
        'classes' => ' group-shaper-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shaper_info|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shapingboard_building_st|profile2|main|default';
  $field_group->group_name = 'group_shapingboard_building_st';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Board Building Stats',
    'weight' => '8',
    'children' => array(
      0 => 'field_user_board_count',
      1 => 'field_bio_industry_status',
      2 => 'field_bio_shaping_interests',
      3 => 'field_bio_influences',
      4 => 'field_shaping_since',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Board Building Stats',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-shapingboard-building-st field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shapingboard_building_st|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shapingboard_building_st|profile2|main|form';
  $field_group->group_name = 'group_shapingboard_building_st';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Board Building Stats',
    'weight' => '8',
    'children' => array(
      0 => 'field_user_board_count',
      1 => 'field_bio_industry_status',
      2 => 'field_bio_shaping_interests',
      3 => 'field_bio_influences',
      4 => 'field_shaping_since',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_shapingboard_building_st|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shipping_information|node|surfshop_surfcraft|form';
  $field_group->group_name = 'group_shipping_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shipping information',
    'weight' => '6',
    'children' => array(
      0 => 'field_surfshop_ship_handling_co',
      1 => 'field_surfshop_shipping_notes',
      2 => 'field_item_location',
      3 => 'field_surfshop_ships_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shipping information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-shipping-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shipping_information|node|surfshop_surfcraft|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shipping_info|node|surfshop_surfcraft|default';
  $field_group->group_name = 'group_shipping_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'surfshop_surfcraft';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shipping information',
    'weight' => '5',
    'children' => array(
      0 => 'field_surfshop_ship_handling_co',
      1 => 'field_surfshop_shipping_notes',
      2 => 'field_item_location',
      3 => 'field_surfshop_ships_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shipping information',
      'instance_settings' => array(
        'classes' => ' group-shipping-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_shipping_info|node|surfshop_surfcraft|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_surfing_stats|profile2|main|default';
  $field_group->group_name = 'group_surfing_stats';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Surfing Stats',
    'weight' => '6',
    'children' => array(
      0 => 'field_user_first_board',
      1 => 'field_user_quiver',
      2 => 'field_bio_favorite_surfers',
      3 => 'field_surfing_since',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Surfing Stats',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-surfing-stats field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_surfing_stats|profile2|main|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_surfing_stats|profile2|main|form';
  $field_group->group_name = 'group_surfing_stats';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Surfing Stats',
    'weight' => '6',
    'children' => array(
      0 => 'field_user_first_board',
      1 => 'field_user_quiver',
      2 => 'field_bio_favorite_surfers',
      3 => 'field_surfing_since',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_surfing_stats|profile2|main|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Board Building Stats');
  t('Buyer payment methods');
  t('Design & construction');
  t('Groups');
  t('Images');
  t('Item Information');
  t('Notification Settings');
  t('Personal Information');
  t('Pricing & Quantity');
  t('Private Message Settings');
  t('Return policy');
  t('Return/Refund Information');
  t('Shaper Information');
  t('Shipping information');
  t('Signature & Avatar');
  t('Surfing Stats');
  t('Username & Password');

  return $field_groups;
}
