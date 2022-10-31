<?php
/**
 * @file
 * swaylocks_marketing.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function swaylocks_marketing_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'swaylocks_weekly_header';
  $mini->category = '';
  $mini->admin_title = 'Swaylocks Weekly header';
  $mini->admin_description = 'Optional header content for swaylocks weekly';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ae6aeabf-c91f-4ed0-b66e-5ad1e3026998';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'swaylocks_weekly_header';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-37fe9787-760c-4fd1-a2bc-66d03a1f924f';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Swaylocks Weekly header',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '37fe9787-760c-4fd1-a2bc-66d03a1f924f';
  $display->content['new-37fe9787-760c-4fd1-a2bc-66d03a1f924f'] = $pane;
  $display->panels['middle'][0] = 'new-37fe9787-760c-4fd1-a2bc-66d03a1f924f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['swaylocks_weekly_header'] = $mini;

  return $export;
}
