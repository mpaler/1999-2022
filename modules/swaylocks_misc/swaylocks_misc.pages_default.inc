<?php
/**
 * @file
 * swaylocks_misc.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function swaylocks_misc_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_0d37fa6a-e976-4540-990d-623d7ef0794b';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Photo Archive Record',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Content (on node.node_author)',
        'keyword' => 'user',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'surfcraft_archive' => 'surfcraft_archive',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7bac677e-1592-402a-9c92-7d7d250ee646';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_0d37fa6a-e976-4540-990d-623d7ef0794b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c7b8a9e2-59e4-4bed-8bfa-d34f2ef760c4';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-28';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'c7b8a9e2-59e4-4bed-8bfa-d34f2ef760c4';
  $display->content['new-c7b8a9e2-59e4-4bed-8bfa-d34f2ef760c4'] = $pane;
  $display->panels['content_main'][0] = 'new-c7b8a9e2-59e4-4bed-8bfa-d34f2ef760c4';
  $pane = new stdClass();
  $pane->pid = 'new-58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div style="padding:15px 15px 15px 15px; margin-bottom: -40px; margin-top: 15px; background-color: #FFF;">
<h4><strong>Added:</strong> %node:created:short</h4>
</div>',
    'format' => 'php_code',
    'substitute' => 1,
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $display->content['new-58dc76f6-4431-465b-bb5f-92fd1bc52723'] = $pane;
  $display->panels['content_main'][1] = 'new-58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $pane = new stdClass();
  $pane->pid = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $pane->panel = 'content_main';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $display->content['new-87720db1-ffc8-4663-ba6c-6eb155bb5270'] = $pane;
  $display->panels['content_main'][2] = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $pane = new stdClass();
  $pane->pid = 'new-79c06a44-35c5-42ea-992f-f31d22486b4d';
  $pane->panel = 'content_main';
  $pane->type = 'node_comment_wrapper';
  $pane->subtype = 'node_comment_wrapper';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'mode' => '1',
    'comments_per_page' => '50',
    'pager_id' => '',
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '79c06a44-35c5-42ea-992f-f31d22486b4d';
  $display->content['new-79c06a44-35c5-42ea-992f-f31d22486b4d'] = $pane;
  $display->panels['content_main'][3] = 'new-79c06a44-35c5-42ea-992f-f31d22486b4d';
  $pane = new stdClass();
  $pane->pid = 'new-c0a7634a-98e7-4285-aa96-852286e06584';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-29';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'c0a7634a-98e7-4285-aa96-852286e06584';
  $display->content['new-c0a7634a-98e7-4285-aa96-852286e06584'] = $pane;
  $display->panels['content_main'][4] = 'new-c0a7634a-98e7-4285-aa96-852286e06584';
  $pane = new stdClass();
  $pane->pid = 'new-1863c9ef-902f-437d-9797-342aa0f431d9';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'user_picture';
  $pane->subtype = 'user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'relationship_entity_from_schema:uid-node-user_1',
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
  $pane->uuid = '1863c9ef-902f-437d-9797-342aa0f431d9';
  $display->content['new-1863c9ef-902f-437d-9797-342aa0f431d9'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-1863c9ef-902f-437d-9797-342aa0f431d9';
  $pane = new stdClass();
  $pane->pid = 'new-33dd1bea-8d5a-40bf-8578-9e5877551df0';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-30';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '33dd1bea-8d5a-40bf-8578-9e5877551df0';
  $display->content['new-33dd1bea-8d5a-40bf-8578-9e5877551df0'] = $pane;
  $display->panels['content_sidebar_second'][1] = 'new-33dd1bea-8d5a-40bf-8578-9e5877551df0';
  $pane = new stdClass();
  $pane->pid = 'new-a3d6fdd6-ff8b-4fab-8f8b-cb44c05f9377';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-31';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'a3d6fdd6-ff8b-4fab-8f8b-cb44c05f9377';
  $display->content['new-a3d6fdd6-ff8b-4fab-8f8b-cb44c05f9377'] = $pane;
  $display->panels['content_sidebar_second'][2] = 'new-a3d6fdd6-ff8b-4fab-8f8b-cb44c05f9377';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_0d37fa6a-e976-4540-990d-623d7ef0794b'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Surfshop Record',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Content (on node.node_author)',
        'keyword' => 'user',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'surfshop_non_surfcraft' => 'surfshop_non_surfcraft',
              'surfshop_surfcraft' => 'surfshop_surfcraft',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7bac677e-1592-402a-9c92-7d7d250ee646';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<p><strong>Added:</strong> %node:created:short</p>
',
    'format' => 'filtered_html',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $display->content['new-58dc76f6-4431-465b-bb5f-92fd1bc52723'] = $pane;
  $display->panels['content_main'][0] = 'new-58dc76f6-4431-465b-bb5f-92fd1bc52723';
  $pane = new stdClass();
  $pane->pid = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $pane->panel = 'content_main';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $display->content['new-87720db1-ffc8-4663-ba6c-6eb155bb5270'] = $pane;
  $display->panels['content_main'][1] = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $pane = new stdClass();
  $pane->pid = 'new-833d413b-d64f-4579-9397-7ef3914ddbca';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'author_pane';
  $pane->subtype = 'author_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'caller' => 'advanced_profile',
    'picture_preset' => '',
    'join_date_type' => 'short',
    'context' => 'relationship_entity_from_schema:uid-node-user_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '833d413b-d64f-4579-9397-7ef3914ddbca';
  $display->content['new-833d413b-d64f-4579-9397-7ef3914ddbca'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-833d413b-d64f-4579-9397-7ef3914ddbca';
  $pane = new stdClass();
  $pane->pid = 'new-e39c4f06-f889-4623-9841-2958cad1661c';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'sharethis-sharethis_block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e39c4f06-f889-4623-9841-2958cad1661c';
  $display->content['new-e39c4f06-f889-4623-9841-2958cad1661c'] = $pane;
  $display->panels['content_sidebar_second'][1] = 'new-e39c4f06-f889-4623-9841-2958cad1661c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-87720db1-ffc8-4663-ba6c-6eb155bb5270';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Forum Detail Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0c8d31a5-7918-4afe-a2aa-b06fe4b10ef8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-974d28e1-4712-4758-a663-fcbaeb810697';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'block-28';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '974d28e1-4712-4758-a663-fcbaeb810697';
  $display->content['new-974d28e1-4712-4758-a663-fcbaeb810697'] = $pane;
  $display->panels['middle'][0] = 'new-974d28e1-4712-4758-a663-fcbaeb810697';
  $pane = new stdClass();
  $pane->pid = 'new-f408b57d-5a2f-4559-b325-3d4d40746c9d';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f408b57d-5a2f-4559-b325-3d4d40746c9d';
  $display->content['new-f408b57d-5a2f-4559-b325-3d4d40746c9d'] = $pane;
  $display->panels['middle'][1] = 'new-f408b57d-5a2f-4559-b325-3d4d40746c9d';
  $pane = new stdClass();
  $pane->pid = 'new-05ec84cc-75dd-49ef-ba3c-ad2fb41533c8';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'block-29';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '05ec84cc-75dd-49ef-ba3c-ad2fb41533c8';
  $display->content['new-05ec84cc-75dd-49ef-ba3c-ad2fb41533c8'] = $pane;
  $display->panels['middle'][2] = 'new-05ec84cc-75dd-49ef-ba3c-ad2fb41533c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f408b57d-5a2f-4559-b325-3d4d40746c9d';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'Board Archive',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'board_archive_categories' => 'board_archive_categories',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
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
  $display->title = '';
  $display->uuid = '6d4179b4-e240-4979-a2c3-19490e67d23e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-167f7b39-7225-4b59-be1a-92ab33d231a0';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-28';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '167f7b39-7225-4b59-be1a-92ab33d231a0';
  $display->content['new-167f7b39-7225-4b59-be1a-92ab33d231a0'] = $pane;
  $display->panels['content_main'][0] = 'new-167f7b39-7225-4b59-be1a-92ab33d231a0';
  $pane = new stdClass();
  $pane->pid = 'new-74591677-06d5-4e73-b1bc-3b2610135310';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfcraft_archive-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
    ),
    'more_link' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '20',
    'offset' => '0',
    'override_title' => 1,
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
  $pane->uuid = '74591677-06d5-4e73-b1bc-3b2610135310';
  $display->content['new-74591677-06d5-4e73-b1bc-3b2610135310'] = $pane;
  $display->panels['content_main'][1] = 'new-74591677-06d5-4e73-b1bc-3b2610135310';
  $pane = new stdClass();
  $pane->pid = 'new-309ace25-4a06-49a3-b182-43c6c056093c';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-29';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '309ace25-4a06-49a3-b182-43c6c056093c';
  $display->content['new-309ace25-4a06-49a3-b182-43c6c056093c'] = $pane;
  $display->panels['content_main'][2] = 'new-309ace25-4a06-49a3-b182-43c6c056093c';
  $pane = new stdClass();
  $pane->pid = 'new-9fe0a203-56b4-4da6-accc-13056549213a';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Archive Categories',
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
  $pane->uuid = '9fe0a203-56b4-4da6-accc-13056549213a';
  $display->content['new-9fe0a203-56b4-4da6-accc-13056549213a'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-9fe0a203-56b4-4da6-accc-13056549213a';
  $pane = new stdClass();
  $pane->pid = 'new-cd717fef-9535-4f8f-b956-3212da17a8eb';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'block-30';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'cd717fef-9535-4f8f-b956-3212da17a8eb';
  $display->content['new-cd717fef-9535-4f8f-b956-3212da17a8eb'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-cd717fef-9535-4f8f-b956-3212da17a8eb';
  $pane = new stdClass();
  $pane->pid = 'new-c52c602f-e746-4868-866d-e133ececa3f8';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'block-31';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'c52c602f-e746-4868-866d-e133ececa3f8';
  $display->content['new-c52c602f-e746-4868-866d-e133ececa3f8'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-c52c602f-e746-4868-866d-e133ececa3f8';
  $pane = new stdClass();
  $pane->pid = 'new-0c74bf08-326d-41f2-a245-942967a510d6';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-7';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
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
  $pane->uuid = '0c74bf08-326d-41f2-a245-942967a510d6';
  $display->content['new-0c74bf08-326d-41f2-a245-942967a510d6'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-0c74bf08-326d-41f2-a245-942967a510d6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-9fe0a203-56b4-4da6-accc-13056549213a';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -98;
  $handler->conf = array(
    'title' => 'Surfshop Category',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'design_length' => 'design_length',
              'non_surfcraft_category' => 'non_surfcraft_category',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_two_sidebars';
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
  $display->title = '';
  $display->uuid = '471f1853-64c1-40ea-9c5c-d53096d510dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b1d721ed-fcf7-47be-8528-07ab2ba3b863';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfshop-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'term_vocabulary',
        'settings' => array(
          'machine_name' => array(
            'design_length' => 'design_length',
          ),
        ),
        'context' => 'argument_term_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'more_link' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '9',
    'offset' => '0',
    'override_title' => 1,
    'override_title_text' => 'Latest Ads in %term:name',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b1d721ed-fcf7-47be-8528-07ab2ba3b863';
  $display->content['new-b1d721ed-fcf7-47be-8528-07ab2ba3b863'] = $pane;
  $display->panels['content_main'][0] = 'new-b1d721ed-fcf7-47be-8528-07ab2ba3b863';
  $pane = new stdClass();
  $pane->pid = 'new-61a57f99-ad15-42bc-95ad-5fa4ed4b767c';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfshop-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'term_vocabulary',
        'settings' => array(
          'machine_name' => array(
            'non_surfcraft_category' => 'non_surfcraft_category',
          ),
        ),
        'context' => 'argument_term_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'more_link' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '9',
    'offset' => '0',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '61a57f99-ad15-42bc-95ad-5fa4ed4b767c';
  $display->content['new-61a57f99-ad15-42bc-95ad-5fa4ed4b767c'] = $pane;
  $display->panels['content_main'][1] = 'new-61a57f99-ad15-42bc-95ad-5fa4ed4b767c';
  $pane = new stdClass();
  $pane->pid = 'new-a6a79f54-63ef-4d87-8eb7-8fe20f356986';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h2>Place Surfshop Ad</h2>

<div>
<p><a href="/node/add/surfshop-surfcraft">Surfcraft For Sale</a>&nbsp;<br />
<a href="/node/add/surfshop-non-surfcraft">Other Ad</a></p>
</div>
',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a6a79f54-63ef-4d87-8eb7-8fe20f356986';
  $display->content['new-a6a79f54-63ef-4d87-8eb7-8fe20f356986'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-a6a79f54-63ef-4d87-8eb7-8fe20f356986';
  $pane = new stdClass();
  $pane->pid = 'new-ed132063-59fe-40d9-9a9d-3d7efe054454';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Surfcraft Categories',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ed132063-59fe-40d9-9a9d-3d7efe054454';
  $display->content['new-ed132063-59fe-40d9-9a9d-3d7efe054454'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-ed132063-59fe-40d9-9a9d-3d7efe054454';
  $pane = new stdClass();
  $pane->pid = 'new-805d7c27-2348-42c8-9003-fe40b0e26e20';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Non-surfcraft Categories',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '805d7c27-2348-42c8-9003-fe40b0e26e20';
  $display->content['new-805d7c27-2348-42c8-9003-fe40b0e26e20'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-805d7c27-2348-42c8-9003-fe40b0e26e20';
  $pane = new stdClass();
  $pane->pid = 'new-e7435f2c-af63-408b-8185-f33e2cbf8394';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-7';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e7435f2c-af63-408b-8185-f33e2cbf8394';
  $display->content['new-e7435f2c-af63-408b-8185-f33e2cbf8394'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-e7435f2c-af63-408b-8185-f33e2cbf8394';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function swaylocks_misc_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'homepage';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_homepage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
          2 => 2,
          3 => 3,
          4 => 4,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '49.9999992963925',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'right' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => '50.000000703607505',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'new_forum_coming_soon',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'new_forum_coming_soon' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'Left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center_',
          1 => 'right__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center_' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'right__' => array(
        'type' => 'region',
        'title' => 'Right',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center__',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'center__' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'new_forum_coming_soon' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'right_' => NULL,
      'center_' => NULL,
      'right__' => NULL,
      'center__' => NULL,
      'left_' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e5fb7e5b-e950-4428-9510-20aca18a8da4';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_homepage_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3d49c0fe-0c7d-4292-8f43-329ff458ebc0';
  $pane->panel = 'left_above';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Forums',
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
  $pane->uuid = '3d49c0fe-0c7d-4292-8f43-329ff458ebc0';
  $display->content['new-3d49c0fe-0c7d-4292-8f43-329ff458ebc0'] = $pane;
  $display->panels['left_above'][0] = 'new-3d49c0fe-0c7d-4292-8f43-329ff458ebc0';
  $pane = new stdClass();
  $pane->pid = 'new-3c301343-d385-43b2-abb5-7dc9680592d3';
  $pane->panel = 'left_below';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Become a supporter</h2>

<p>If you want to help out financially, whether that\'s showing gratitude for the past, helping out the present, or contributing to the future Swaylock\'s please consider contributing financially over on our Patreon site. Whether as a one time contribution or as an ongoing patron/supporter, every dollar will help.</p>
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
  $pane->uuid = '3c301343-d385-43b2-abb5-7dc9680592d3';
  $display->content['new-3c301343-d385-43b2-abb5-7dc9680592d3'] = $pane;
  $display->panels['left_below'][0] = 'new-3c301343-d385-43b2-abb5-7dc9680592d3';
  $pane = new stdClass();
  $pane->pid = 'new-d45f5aea-9fd8-4e83-abe4-f749cfd9be4d';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>About Swaylock\'s</h2>

<p>Since 1999 Swaylocks.com has been the number one online resource for high-quality information related to surfboard and surfcraft design, construction, manufacture &amp; history.</p>

<h2>The next 23 years?</h2>

<p>In late 2022, in an effort to cut costs while preserving the rich history and&nbsp;accumulated&nbsp;knowledge,&nbsp;Swaylock\'s converted from an active forum to a static archive (the site you\'re looking at now).</p>

<p>Will Swaylock\'s be frozen in time or can it rise into something bigger and better? Only time will tell...</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<ul>
</ul>
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
  $pane->uuid = 'd45f5aea-9fd8-4e83-abe4-f749cfd9be4d';
  $display->content['new-d45f5aea-9fd8-4e83-abe4-f749cfd9be4d'] = $pane;
  $display->panels['middle'][0] = 'new-d45f5aea-9fd8-4e83-abe4-f749cfd9be4d';
  $pane = new stdClass();
  $pane->pid = 'new-00a3934a-c922-46d7-bb91-e9f4d0e1bfbf';
  $pane->panel = 'right_above';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-1';
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
  $pane->uuid = '00a3934a-c922-46d7-bb91-e9f4d0e1bfbf';
  $display->content['new-00a3934a-c922-46d7-bb91-e9f4d0e1bfbf'] = $pane;
  $display->panels['right_above'][0] = 'new-00a3934a-c922-46d7-bb91-e9f4d0e1bfbf';
  $pane = new stdClass();
  $pane->pid = 'new-cfb04df3-4c63-47dd-bd56-81a0355430e8';
  $pane->panel = 'right_below';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h2>Stay notified</h2>

<p><iframe frameborder="0" height="320" scrolling="no" src="https://swaylocks.substack.com/embed" style="border:1px solid #EEE; background:white;" width="480"></iframe></p>
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
  $pane->uuid = 'cfb04df3-4c63-47dd-bd56-81a0355430e8';
  $display->content['new-cfb04df3-4c63-47dd-bd56-81a0355430e8'] = $pane;
  $display->panels['right_below'][0] = 'new-cfb04df3-4c63-47dd-bd56-81a0355430e8';
  $pane = new stdClass();
  $pane->pid = 'new-43477266-0218-4025-9578-f7ae9b28c6f5';
  $pane->panel = 'top';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>The Archives 1999-2022</h1>
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
  $pane->uuid = '43477266-0218-4025-9578-f7ae9b28c6f5';
  $display->content['new-43477266-0218-4025-9578-f7ae9b28c6f5'] = $pane;
  $display->panels['top'][0] = 'new-43477266-0218-4025-9578-f7ae9b28c6f5';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-3d49c0fe-0c7d-4292-8f43-329ff458ebc0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'members';
  $page->task = 'page';
  $page->admin_title = 'Members';
  $page->admin_description = '';
  $page->path = 'members';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_right';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
          1 => 1,
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'column',
        'width' => '300',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => 'sideright',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sideright',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'sideright' => array(
        'type' => 'region',
        'title' => 'sideright',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sideright' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Member Directory';
  $display->uuid = '4b3041a3-b60e-5024-a584-df137a9f10dd';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_members_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-71e49f78-2143-43a4-aacd-ce3007eb99e9';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'members';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => 'members',
    'display' => 'page_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '71e49f78-2143-43a4-aacd-ce3007eb99e9';
  $display->content['new-71e49f78-2143-43a4-aacd-ce3007eb99e9'] = $pane;
  $display->panels['content_main'][0] = 'new-71e49f78-2143-43a4-aacd-ce3007eb99e9';
  $pane = new stdClass();
  $pane->pid = 'new-22484365-951f-4576-a656-c8d63f9d71e8';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-6';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '22484365-951f-4576-a656-c8d63f9d71e8';
  $display->content['new-22484365-951f-4576-a656-c8d63f9d71e8'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-22484365-951f-4576-a656-c8d63f9d71e8';
  $pane = new stdClass();
  $pane->pid = 'new-05bf5dcd-51ab-425d-ab14-02efd4ffdcf8';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '05bf5dcd-51ab-425d-ab14-02efd4ffdcf8';
  $display->content['new-05bf5dcd-51ab-425d-ab14-02efd4ffdcf8'] = $pane;
  $display->panels['content_sidebar_second'][1] = 'new-05bf5dcd-51ab-425d-ab14-02efd4ffdcf8';
  $pane = new stdClass();
  $pane->pid = 'new-a02ca926-cdda-4f15-8730-ba5270c38711';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'block';
  $pane->subtype = 'block-4';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'a02ca926-cdda-4f15-8730-ba5270c38711';
  $display->content['new-a02ca926-cdda-4f15-8730-ba5270c38711'] = $pane;
  $display->panels['content_sidebar_second'][2] = 'new-a02ca926-cdda-4f15-8730-ba5270c38711';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'photo_archive';
  $page->task = 'page';
  $page->admin_title = 'Photo Archive';
  $page->admin_description = '';
  $page->path = 'archive';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Board Archive',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_photo_archive_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'photo_archive';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_first' => NULL,
      'content_sidebar_second' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Swaylock\'s Board Archive';
  $display->uuid = '498a90ba-72f9-47a4-bfe9-1114295018aa';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_photo_archive_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1f74ebc2-14c9-4eb5-bb68-02054769b17d';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-28';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '1f74ebc2-14c9-4eb5-bb68-02054769b17d';
  $display->content['new-1f74ebc2-14c9-4eb5-bb68-02054769b17d'] = $pane;
  $display->panels['content_main'][0] = 'new-1f74ebc2-14c9-4eb5-bb68-02054769b17d';
  $pane = new stdClass();
  $pane->pid = 'new-6107f46d-70af-49d9-af7a-a4a56f6caa4e';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfcraft_archive-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link_to_view' => 0,
    'more_link' => 0,
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
    'offset' => '6',
    'path' => '',
    'fields_override' => array(
      'field_archive_images' => 1,
      'title' => 1,
      'created' => 1,
      'name' => 1,
      'field_archive_category' => 1,
    ),
    'override_title' => 1,
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
  $pane->uuid = '6107f46d-70af-49d9-af7a-a4a56f6caa4e';
  $display->content['new-6107f46d-70af-49d9-af7a-a4a56f6caa4e'] = $pane;
  $display->panels['content_main'][1] = 'new-6107f46d-70af-49d9-af7a-a4a56f6caa4e';
  $pane = new stdClass();
  $pane->pid = 'new-956c3f1b-d4ba-4827-8b75-b15c9df44369';
  $pane->panel = 'content_main';
  $pane->type = 'block';
  $pane->subtype = 'block-29';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '956c3f1b-d4ba-4827-8b75-b15c9df44369';
  $display->content['new-956c3f1b-d4ba-4827-8b75-b15c9df44369'] = $pane;
  $display->panels['content_main'][2] = 'new-956c3f1b-d4ba-4827-8b75-b15c9df44369';
  $pane = new stdClass();
  $pane->pid = 'new-f9ca5774-8310-429e-8692-87d3b5deaca0';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Archive Categories',
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
  $pane->uuid = 'f9ca5774-8310-429e-8692-87d3b5deaca0';
  $display->content['new-f9ca5774-8310-429e-8692-87d3b5deaca0'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-f9ca5774-8310-429e-8692-87d3b5deaca0';
  $pane = new stdClass();
  $pane->pid = 'new-295c3040-032a-4182-b1b3-5b7e1268a05e';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'block-30';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = '295c3040-032a-4182-b1b3-5b7e1268a05e';
  $display->content['new-295c3040-032a-4182-b1b3-5b7e1268a05e'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-295c3040-032a-4182-b1b3-5b7e1268a05e';
  $pane = new stdClass();
  $pane->pid = 'new-fc93e52b-b896-4884-aa89-be5df85e37c8';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'block-31';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'fc93e52b-b896-4884-aa89-be5df85e37c8';
  $display->content['new-fc93e52b-b896-4884-aa89-be5df85e37c8'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-fc93e52b-b896-4884-aa89-be5df85e37c8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-f9ca5774-8310-429e-8692-87d3b5deaca0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['photo_archive'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'surfshop';
  $page->task = 'page';
  $page->admin_title = 'Surfshop';
  $page->admin_description = '';
  $page->path = 'surfshop';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_surfshop_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'surfshop';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'surfshop',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_left';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_33_66_top' => NULL,
      'two_33_66_first' => NULL,
      'two_33_66_second' => NULL,
      'two_33_66_bottom' => NULL,
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
  $display->title = 'Swaylock\'s Surfshop';
  $display->uuid = '062635de-e59d-47cf-b36d-c1a6ef00bb79';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_surfshop_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c1f08af9-951c-4a77-8cea-f9d24cdc90e4';
  $pane->panel = 'content_main';
  $pane->type = 'views_panes';
  $pane->subtype = 'surfshop-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
    ),
    'override_title' => 1,
    'override_title_text' => 'Newest Ads in the Surfshop',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c1f08af9-951c-4a77-8cea-f9d24cdc90e4';
  $display->content['new-c1f08af9-951c-4a77-8cea-f9d24cdc90e4'] = $pane;
  $display->panels['content_main'][0] = 'new-c1f08af9-951c-4a77-8cea-f9d24cdc90e4';
  $pane = new stdClass();
  $pane->pid = 'new-e84319be-fae7-4a14-9b67-24ffb4d6f3d5';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h2>Place Surfshop Ad</h2>

<div>
<p><a href="/node/add/surfshop-surfcraft" style="color: rgb(102, 153, 204);">Surfcraft For Sale</a>&nbsp;<br />
<a href="/node/add/surfshop-non-surfcraft" style="color: rgb(102, 153, 204);">Other Ad</a></p>
</div>
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
  $pane->uuid = 'e84319be-fae7-4a14-9b67-24ffb4d6f3d5';
  $display->content['new-e84319be-fae7-4a14-9b67-24ffb4d6f3d5'] = $pane;
  $display->panels['content_sidebar_first'][0] = 'new-e84319be-fae7-4a14-9b67-24ffb4d6f3d5';
  $pane = new stdClass();
  $pane->pid = 'new-14093a64-4ecc-4f0e-8e1f-2162fbabe7f2';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Surfcraft Categories',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '14093a64-4ecc-4f0e-8e1f-2162fbabe7f2';
  $display->content['new-14093a64-4ecc-4f0e-8e1f-2162fbabe7f2'] = $pane;
  $display->panels['content_sidebar_first'][1] = 'new-14093a64-4ecc-4f0e-8e1f-2162fbabe7f2';
  $pane = new stdClass();
  $pane->pid = 'new-37a7b76d-1ef6-4f72-ac23-7b0e151319d3';
  $pane->panel = 'content_sidebar_first';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Non-surfcraft Categories',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '37a7b76d-1ef6-4f72-ac23-7b0e151319d3';
  $display->content['new-37a7b76d-1ef6-4f72-ac23-7b0e151319d3'] = $pane;
  $display->panels['content_sidebar_first'][2] = 'new-37a7b76d-1ef6-4f72-ac23-7b0e151319d3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['surfshop'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'swaylopedia_main';
  $page->task = 'page';
  $page->admin_title = 'swaylopedia-main';
  $page->admin_description = '';
  $page->path = 'swaylopedia';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_swaylopedia_main_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'swaylopedia_main';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'swaylopedia',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'forumplus_sidebar_right';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
      'content_main' => NULL,
      'content_sidebar_second' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Swaylopedia - The Surfcraft Knowledgebase';
  $display->uuid = '4a700f96-6c20-491a-953f-a943793272ab';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_swaylopedia_main_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-aa88b51a-5f9b-4fb2-98ed-0dc37f76bc66';
  $pane->panel = 'content_main';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '<none>',
    'body' => '<h2>Contribute To Swaylopedia</h2>

<div class="content" style="color: rgb(0, 0, 0); font-family: Arial, Helvetica, \'Bitstream Vera Sans\', sans-serif; font-size: 13.63636302947998px; line-height: 18.125px;">
<p>Earn fame &amp; respect throughout the surfing world. Please contribute your knowledge &amp; experience with one of the following:</p>
</div>

<ul>
	<li><a href="/node/add/book">Write an article</a></li>
	<li><a href="/node/add/glossary">Define a glossary term</a></li>
	<li><a href="/node/add/image">Add an image</a></li>
</ul>
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
  $pane->uuid = 'aa88b51a-5f9b-4fb2-98ed-0dc37f76bc66';
  $display->content['new-aa88b51a-5f9b-4fb2-98ed-0dc37f76bc66'] = $pane;
  $display->panels['content_main'][0] = 'new-aa88b51a-5f9b-4fb2-98ed-0dc37f76bc66';
  $pane = new stdClass();
  $pane->pid = 'new-539971fa-fb40-4b37-82b6-f83acfaf3cb4';
  $pane->panel = 'content_main';
  $pane->type = 'views';
  $pane->subtype = 'swaylopedia_main';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '539971fa-fb40-4b37-82b6-f83acfaf3cb4';
  $display->content['new-539971fa-fb40-4b37-82b6-f83acfaf3cb4'] = $pane;
  $display->panels['content_main'][1] = 'new-539971fa-fb40-4b37-82b6-f83acfaf3cb4';
  $pane = new stdClass();
  $pane->pid = 'new-a24601dd-91d3-431b-b247-606a0d0ed093';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'views';
  $pane->subtype = 'glossary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 1,
    'use_pager' => 1,
    'nodes_per_page' => '36',
    'pager_id' => '1',
    'offset' => '0',
    'more_link' => 1,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 1,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a24601dd-91d3-431b-b247-606a0d0ed093';
  $display->content['new-a24601dd-91d3-431b-b247-606a0d0ed093'] = $pane;
  $display->panels['content_sidebar_second'][0] = 'new-a24601dd-91d3-431b-b247-606a0d0ed093';
  $pane = new stdClass();
  $pane->pid = 'new-cee5a7c9-66ef-4186-a6ae-7b6a0abb5862';
  $pane->panel = 'content_sidebar_second';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Handbooks',
    'body' => '<div class="item-list"><ul><li><a href="/swaylopedia/handbooks/getting-involved-swaylocks">Getting Involved with Swaylock\'s</a></li><li><a href="/swaylopedia/handbooks/how-tos">How To\'s</a></li><li><a href="/swaylopedia/handbooks/tips-tricks">Tips &amp; Tricks</a></li><li><a href="/swaylopedia/handbooks/troubleshooting-faqs">Troubleshooting FAQs</a></li></ul></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'cee5a7c9-66ef-4186-a6ae-7b6a0abb5862';
  $display->content['new-cee5a7c9-66ef-4186-a6ae-7b6a0abb5862'] = $pane;
  $display->panels['content_sidebar_second'][1] = 'new-cee5a7c9-66ef-4186-a6ae-7b6a0abb5862';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['swaylopedia_main'] = $page;

  return $pages;

}
