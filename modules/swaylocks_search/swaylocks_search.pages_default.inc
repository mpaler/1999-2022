<?php
/**
 * @file
 * swaylocks_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function swaylocks_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_swaylocks_empty_site_search__panel_context_22eeb2b7-f5b3-4c85-a281-d2ee57269ddf';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'swaylocks_empty_site_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Swaylock\'s Search: Empty Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content_main' => NULL,
      'content_sidebar_first' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Swaylock\'s Site Search';
  $display->uuid = 'bb8cb78b-ba24-43e9-b397-94b351269880';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_swaylocks_empty_site_search__panel_context_22eeb2b7-f5b3-4c85-a281-d2ee57269ddf';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5fd26e6f-67a2-41d7-8406-435260275620';
  $pane->panel = 'content_main';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'swaylocks_site_search',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5fd26e6f-67a2-41d7-8406-435260275620';
  $display->content['new-5fd26e6f-67a2-41d7-8406-435260275620'] = $pane;
  $display->panels['content_main'][0] = 'new-5fd26e6f-67a2-41d7-8406-435260275620';
  $pane = new stdClass();
  $pane->pid = 'new-7acb634f-e9e6-457d-80f8-960428a4c95b';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-sort';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7acb634f-e9e6-457d-80f8-960428a4c95b';
  $display->content['new-7acb634f-e9e6-457d-80f8-960428a4c95b'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-7acb634f-e9e6-457d-80f8-960428a4c95b';
  $pane = new stdClass();
  $pane->pid = 'new-548a4167-b41a-46a6-a119-c9b8a63d34d7';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '548a4167-b41a-46a6-a119-c9b8a63d34d7';
  $display->content['new-548a4167-b41a-46a6-a119-c9b8a63d34d7'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-548a4167-b41a-46a6-a119-c9b8a63d34d7';
  $pane = new stdClass();
  $pane->pid = 'new-39ebca1a-8256-4c6e-b290-14a2c7ade528';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-wWWinJ0eOefOtAMbjo2yl86Mnf1rO12j';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '39ebca1a-8256-4c6e-b290-14a2c7ade528';
  $display->content['new-39ebca1a-8256-4c6e-b290-14a2c7ade528'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-39ebca1a-8256-4c6e-b290-14a2c7ade528';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5fd26e6f-67a2-41d7-8406-435260275620';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_swaylocks_empty_site_search__panel_context_22eeb2b7-f5b3-4c85-a281-d2ee57269ddf'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_swaylocks_site_search__panel_context_ce03c1a2-28f5-4a5b-b078-6b2fe10568e9';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'swaylocks_site_search';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'title' => 'Swaylock\'s Search: Global Search',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'search/site',
          ),
          'context' => 'empty',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_first' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Swaylock\'s Site Search';
  $display->uuid = 'c846381a-31a8-49f6-913c-ecb8f3a23852';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'pm_existing_pages_swaylocks_site_search__panel_context_ce03c1a2-28f5-4a5b-b078-6b2fe10568e9';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ae5c3c61-6a80-44f1-951f-53c0cb6723ae';
  $pane->panel = 'content_main';
  $pane->type = 'pm_existing_pages';
  $pane->subtype = 'pm_existing_pages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    0 => 'task_id',
    'task_id' => 'swaylocks_site_search',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ae5c3c61-6a80-44f1-951f-53c0cb6723ae';
  $display->content['new-ae5c3c61-6a80-44f1-951f-53c0cb6723ae'] = $pane;
  $display->panels['content_main'][0] = 'new-ae5c3c61-6a80-44f1-951f-53c0cb6723ae';
  $pane = new stdClass();
  $pane->pid = 'new-e38d9ef2-ddc2-4932-96eb-7c28aa098772';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-sort';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e38d9ef2-ddc2-4932-96eb-7c28aa098772';
  $display->content['new-e38d9ef2-ddc2-4932-96eb-7c28aa098772'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-e38d9ef2-ddc2-4932-96eb-7c28aa098772';
  $pane = new stdClass();
  $pane->pid = 'new-de1bbd16-0b99-496d-a965-c7d17f53c46c';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'de1bbd16-0b99-496d-a965-c7d17f53c46c';
  $display->content['new-de1bbd16-0b99-496d-a965-c7d17f53c46c'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-de1bbd16-0b99-496d-a965-c7d17f53c46c';
  $pane = new stdClass();
  $pane->pid = 'new-62ebe4ee-296a-49c6-b210-297362499751';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-wWWinJ0eOefOtAMbjo2yl86Mnf1rO12j';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '62ebe4ee-296a-49c6-b210-297362499751';
  $display->content['new-62ebe4ee-296a-49c6-b210-297362499751'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-62ebe4ee-296a-49c6-b210-297362499751';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ae5c3c61-6a80-44f1-951f-53c0cb6723ae';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_swaylocks_site_search__panel_context_ce03c1a2-28f5-4a5b-b078-6b2fe10568e9'] = $handler;

  return $export;
}
