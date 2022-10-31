<?php
/**
 * @file
 * swaylocks_misc.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function swaylocks_misc_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'ad_block_placeholder';
  $mini->category = '';
  $mini->admin_title = 'Ad Block Placeholder';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '12d0a3f2-0a73-45fc-9f76-4ccf5c0031fa';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'ad_block_placeholder';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4a436c7e-85c3-4b74-9339-ec0a3ad8bdcb';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p><span class="adblock">&nbsp;</span></p>
',
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
  $pane->uuid = '4a436c7e-85c3-4b74-9339-ec0a3ad8bdcb';
  $display->content['new-4a436c7e-85c3-4b74-9339-ec0a3ad8bdcb'] = $pane;
  $display->panels['middle'][0] = 'new-4a436c7e-85c3-4b74-9339-ec0a3ad8bdcb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['ad_block_placeholder'] = $mini;

  return $export;
}
