<?php
/**
 * @file
 * swaylocks_base.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function swaylocks_base_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: user_permission
  $overrides["user_permission.post comments.roles|authenticated user"]["DELETED"] = TRUE;
  $overrides["user_permission.post comments.roles|moderator"] = 'moderator';
  $overrides["user_permission.post comments.roles|trusted"] = 'trusted';
  $overrides["user_permission.skip comment approval.roles|authenticated user"]["DELETED"] = TRUE;
  $overrides["user_permission.skip comment approval.roles|moderator"] = 'moderator';
  $overrides["user_permission.skip comment approval.roles|trusted"] = 'trusted';

 return $overrides;
}
