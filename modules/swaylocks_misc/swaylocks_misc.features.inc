<?php
/**
 * @file
 * swaylocks_misc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function swaylocks_misc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function swaylocks_misc_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function swaylocks_misc_image_default_styles() {
  $styles = array();

  // Exported image style: 100x75.
  $styles['100x75'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 75,
        ),
        'weight' => 1,
      ),
    ),
    'label' => '100x75',
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function swaylocks_misc_default_message_type() {
  $items = array();
  $items['swaylocks_activity_comment_liked'] = entity_import('message_type', '{
    "name" : "swaylocks_activity_comment_liked",
    "description" : "Swaylocks Activity: Comment Liked",
    "argument_keys" : [ "!action" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ctable\\u003E\\u003Ctr\\u003E\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\u003Ctd\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E !action a \\u003Ca href=\\u0022[message:field-target-comments:0:url]\\u0022\\u003Ecomment\\u003C\\/a\\u003E in the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\u003C\\/tr\\u003E\\u003C\\/table\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ctable\\u003E\\n\\u003Ctr\\u003E\\n\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\n\\u003Ctd\\u003E\\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Auser%3Aurl%3Aabsolute%5D\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E !action a \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-comments%3A0%3Aurl%5D\\u0022\\u003Ecomment\\u003C\\/a\\u003E in the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-nodes%3A0%3Aurl%5D\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\n\\u003C\\/tr\\u003E\\n\\u003C\\/table\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['swaylocks_activity_node_created_no_groups'] = entity_import('message_type', '{
    "name" : "swaylocks_activity_node_created_no_groups",
    "description" : "Swaylocks Activity: Node created no groups",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ctable\\u003E\\u003Ctr\\u003E\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\u003Ctd\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\u003C\\/tr\\u003E\\u003C\\/table\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ctable\\u003E\\n\\u003Ctr\\u003E\\n\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\n\\u003Ctd\\u003E\\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Auser%3Aurl%3Aabsolute%5D\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E created the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-nodes%3A0%3Aurl%5D\\u0022\\u003E[message:field-target-nodes:0:title_field]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\n\\u003C\\/tr\\u003E\\n\\u003C\\/table\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['swaylocks_activity_node_liked'] = entity_import('message_type', '{
    "name" : "swaylocks_activity_node_liked",
    "description" : "Swaylocks Activity: Node Liked",
    "argument_keys" : [ "!action" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ctable\\u003E\\u003Ctr\\u003E\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\u003Ctd\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E !action the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\u003C\\/tr\\u003E\\u003C\\/table\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ctable\\u003E\\n\\u003Ctr\\u003E\\n\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\n\\u003Ctd\\u003E\\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Auser%3Aurl%3Aabsolute%5D\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E !action the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-nodes%3A0%3Aurl%5D\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\n\\u003C\\/tr\\u003E\\n\\u003C\\/table\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['swaylocks_activity_streams_comment_created_forums'] = entity_import('message_type', '{
    "name" : "swaylocks_activity_streams_comment_created_forums",
    "description" : "Swaylocks Activity: New comment",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Ctable\\u003E\\u003Ctr\\u003E\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\u003Ctd\\u003E\\u003Ca href=\\u0022[message:user:url:absolute]\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E \\u003Ca href=\\u0022[message:field-target-comments:0:url]\\u0022\\u003Ecommented\\u003C\\/a\\u003E on the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022[message:field-target-nodes:0:url]\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\u003C\\/tr\\u003E\\u003C\\/table\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Ctable\\u003E\\n\\u003Ctr\\u003E\\n\\u003Ctd width=\\u002240\\u0022\\u003E[message:user:picture]\\u003C\\/td\\u003E\\n\\u003Ctd\\u003E\\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Auser%3Aurl%3Aabsolute%5D\\u0022\\u003E[message:user:name]\\u003C\\/a\\u003E \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-comments%3A0%3Aurl%5D\\u0022\\u003Ecommented\\u003C\\/a\\u003E on the [message:field-target-nodes:0:content-type] \\u003Ca href=\\u0022http:\\/\\/swaylocks.local\\/%5Bmessage%3Afield-target-nodes%3A0%3Aurl%5D\\u0022\\u003E[message:field-target-nodes:0:title]\\u003C\\/a\\u003E [message:timestamp:time_ago_dynamic].\\u003C\\/td\\u003E\\n\\u003C\\/tr\\u003E\\n\\u003C\\/table\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['swaylocks_notify_new_comment_no_groups'] = entity_import('message_type', '{
    "name" : "swaylocks_notify_new_comment_no_groups",
    "description" : "Swaylocks Notify: New comment no groups",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003E[Swaylock\\u0027s]\\u0026nbsp;New comment posted on\\u0026nbsp;\\u0022[message:field-target-nodes:0:title]\\u0022\\u0026nbsp;by [message:field-target-comments:0:author]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[Swaylock\\u0027s]\\u00a0New comment posted on\\u00a0\\u0022[message:field-target-nodes:0:title]\\u0022\\u00a0by [message:field-target-comments:0:author]\\u003C\\/p\\u003E"
        },
        {
          "value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[message:field-target-comments:0:author] commented on [message:field-target-nodes:0:title_field]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003ERead and respond: [message:field-target-comments:0:url]\\u003Cbr \\/\\u003E\\r\\nUpdate your notification settings: [message:user:edit-url]\\/notification-settings\\u0026nbsp;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E---\\u003Cbr \\/\\u003E\\r\\n[site:name]\\u003Cbr \\/\\u003E\\r\\n[site:slogan]\\u003Cbr \\/\\u003E\\r\\n[site:url]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003E[message:field-target-comments:0:author] commented on [message:field-target-nodes:0:title_field]\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003ERead and respond: [message:field-target-comments:0:url]\\u003Cbr \\/\\u003E\\nUpdate your notification settings: [message:user:edit-url]\\/notification-settings\\u00a0\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003E---\\u003Cbr \\/\\u003E\\n[site:name]\\u003Cbr \\/\\u003E\\n[site:slogan]\\u003Cbr \\/\\u003E\\n[site:url]\\u003C\\/p\\u003E"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['swaylocks_notify_new_comment_no_groups2'] = entity_import('message_type', '{
    "name" : "swaylocks_notify_new_comment_no_groups2",
    "description" : "swaylocks_notify_new_comment_no_groups2",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "",
    "arguments" : null,
    "message_text" : [],
    "rdf_mapping" : []
  }');
  $items['swaylocks_notify_non_group_node_created'] = entity_import('message_type', '{
    "name" : "swaylocks_notify_non_group_node_created",
    "description" : "Swaylocks Notify: Non-group node created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "New [message:field-target-nodes:0:content-type] on [site:name]: [message:field-target-nodes:0:title_field]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew [message:field-target-nodes:0:content-type] on [site:name]: [message:field-target-nodes:0:title_field]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hi [message:user:name],\\r\\n\\r\\n[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title_field]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nPermalink: [message:field-target-nodes:0:url]\\r\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title_field]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:body]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EPermalink: [message:field-target-nodes:0:url]\\u003Cbr \\/\\u003E\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\u003C\\/p\\u003E\\n\\u003Cp\\u003EChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function swaylocks_misc_node_info() {
  $items = array(
    'image' => array(
      'name' => t('Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'surfcraft_archive' => array(
      'name' => t('Surfcraft Archive'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'surfshop_non_surfcraft' => array(
      'name' => t('Surfshop - non-surfcraft'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'surfshop_surfcraft' => array(
      'name' => t('Surfshop - Surfcraft'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function swaylocks_misc_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Profile",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
