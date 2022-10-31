<?php
/**
 * @file
 * pages_context.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function pages_context_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'active_topics';
  $mini->category = '';
  $mini->admin_title = 'Active Topics';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd9c8bb01-27cc-41d4-84ed-05eca568a333';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'active_topics';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a3121a31-686d-4ea5-942b-5b2132bdf1c2';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'sways_advanced_forum_topic_list-panel_pane_1';
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
  $pane->uuid = 'a3121a31-686d-4ea5-942b-5b2132bdf1c2';
  $display->content['new-a3121a31-686d-4ea5-942b-5b2132bdf1c2'] = $pane;
  $display->panels['one_main'][0] = 'new-a3121a31-686d-4ea5-942b-5b2132bdf1c2';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-a3121a31-686d-4ea5-942b-5b2132bdf1c2';
  $mini->display = $display;
  $export['active_topics'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'new_topics';
  $mini->category = '';
  $mini->admin_title = 'New Topics';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4f89e8fb-1629-47b4-8204-ad303e4dbe9c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'new_topics';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8c3d7b76-11f8-4566-8563-39a447400158';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'sways_advanced_forum_topic_list-panel_pane_2';
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
  $pane->uuid = '8c3d7b76-11f8-4566-8563-39a447400158';
  $display->content['new-8c3d7b76-11f8-4566-8563-39a447400158'] = $pane;
  $display->panels['one_main'][0] = 'new-8c3d7b76-11f8-4566-8563-39a447400158';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-8c3d7b76-11f8-4566-8563-39a447400158';
  $mini->display = $display;
  $export['new_topics'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'photo_archive_slideshow';
  $mini->category = '';
  $mini->admin_title = 'Photo archive slideshow';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'c2ebcfad-f9c2-4cae-8b6e-1213405f497b';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'photo_archive_slideshow';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-18270993-5905-40d4-ab7a-2a03d11ea52e';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfcraft_archive-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link_to_view' => 0,
    'more_link' => 0,
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '6',
    'offset' => '0',
    'path' => '',
    'fields_override' => array(
      'field_archive_images' => 1,
      'title' => 1,
      'created' => 0,
      'name' => 1,
      'field_archive_category' => 1,
    ),
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
  $pane->uuid = '18270993-5905-40d4-ab7a-2a03d11ea52e';
  $display->content['new-18270993-5905-40d4-ab7a-2a03d11ea52e'] = $pane;
  $display->panels['one_main'][0] = 'new-18270993-5905-40d4-ab7a-2a03d11ea52e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-18270993-5905-40d4-ab7a-2a03d11ea52e';
  $mini->display = $display;
  $export['photo_archive_slideshow'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'surfshop_surfcraft';
  $mini->category = '';
  $mini->admin_title = 'Surfshop Surfcraft';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4aceec0b-aa1e-4243-9218-c44bb67d0ff1';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'surfshop_surfcraft';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bd48b931-cc40-4190-83a2-b05cd43ee805';
  $pane->panel = 'one_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfshop-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'more_link' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '9',
    'offset' => '0',
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
  $pane->uuid = 'bd48b931-cc40-4190-83a2-b05cd43ee805';
  $display->content['new-bd48b931-cc40-4190-83a2-b05cd43ee805'] = $pane;
  $display->panels['one_main'][0] = 'new-bd48b931-cc40-4190-83a2-b05cd43ee805';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-bd48b931-cc40-4190-83a2-b05cd43ee805';
  $mini->display = $display;
  $export['surfshop_surfcraft'] = $mini;

  return $export;
}
