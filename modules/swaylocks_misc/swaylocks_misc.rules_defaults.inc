<?php
/**
 * @file
 * swaylocks_misc.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function swaylocks_misc_default_rules_configuration() {
  $items = array();
  $items['rules_points_assign_points_to_new_user'] = entity_import('rules_config', '{ "rules_points_assign_points_to_new_user" : {
      "LABEL" : "Points: Assign Points to New User",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Points" ],
      "REQUIRES" : [ "userpoints_rules", "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "account" ],
            "points" : "10",
            "tid" : "0",
            "entity" : [ "" ],
            "operation" : "Insert",
            "display" : "1",
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['swaylocks_misc_userpoints_demote_roles_cloned'] = entity_import('rules_config', '{ "swaylocks_misc_userpoints_demote_roles_cloned" : {
      "LABEL" : "Userpoints Demote Roles Cloned",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "userpoints_rules", "rules", "php" ],
      "ON" : { "userpoints_event_points_awarded_after" : [] },
      "IF" : [
        { "userpoints_condition_check_points" : {
            "user" : [ "userpoints-transaction:user" ],
            "tid" : "0",
            "threshold" : "10",
            "comparison" : "lt"
          }
        },
        { "AND" : [
            { "user_has_role" : {
                "account" : [ "userpoints-transaction:user" ],
                "roles" : { "value" : { "9" : "9" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "userpoints-transaction:user" ],
            "roles" : { "value" : { "9" : "9" } }
          }
        },
        { "drupal_message" : {
            "message" : "[userpoints-transaction:user] has less than \\u003C?php print variable_get(\\u0027trusted_userpoints\\u0027); ?\\u003E userpoints and is no longer a \\u0022trusted\\u0022 Swaylock\\u0027s member.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  $items['swaylocks_misc_userpoints_promote_roles_cloned'] = entity_import('rules_config', '{ "swaylocks_misc_userpoints_promote_roles_cloned" : {
      "LABEL" : "Userpoints Promote Roles Cloned",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "userpoints_rules", "rules", "php" ],
      "ON" : { "userpoints_event_points_awarded_after" : [] },
      "IF" : [
        { "userpoints_condition_check_points" : {
            "user" : [ "userpoints-transaction:user" ],
            "tid" : "0",
            "threshold" : "10",
            "comparison" : "ge"
          }
        },
        { "AND" : [
            { "NOT user_has_role" : {
                "account" : [ "userpoints-transaction:user" ],
                "roles" : { "value" : { "9" : "9" } }
              }
            }
          ]
        }
      ],
      "DO" : [
        { "user_add_role" : {
            "account" : [ "userpoints-transaction:user" ],
            "roles" : { "value" : { "9" : "9" } }
          }
        },
        { "drupal_message" : {
            "message" : "[userpoints-transaction:user] has \\u003C?php print variable_get(\\u0027trusted_userpoints\\u0027); ?\\u003E userpoints and is now a \\u0022trusted\\u0022 Swaylock\\u0027s member.",
            "repeat" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
