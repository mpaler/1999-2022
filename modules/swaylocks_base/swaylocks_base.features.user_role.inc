<?php
/**
 * @file
 * swaylocks_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function swaylocks_base_user_default_roles() {
  $roles = array();

  // Exported role: author.
  $roles['author'] = array(
    'name' => 'author',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: exmod.
  $roles['exmod'] = array(
    'name' => 'exmod',
    'weight' => 5,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 6,
  );

  // Exported role: trusted.
  $roles['trusted'] = array(
    'name' => 'trusted',
    'weight' => 7,
  );

  return $roles;
}
