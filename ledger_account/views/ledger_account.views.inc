<?php

/**
 * @file
 * Ledger Account Views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_account_views_data_alter(&$data) {

  // Replace the account name field handler with one that provides a "Link this field to" option.
  $data['ledger_account']['name']['field']['handler'] = 'ledger_account_handler_field';

  // Replace the field handler for the account type so that it uses the human-readable type.
  $data['ledger_account']['type']['field']['handler'] = 'ledger_account_handler_field_account_type';

  // Add a field for account view link.
  $data['ledger_account']['view_account'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the account.'),
      'handler' => 'ledger_account_handler_field_link',
    ),
  );

  // Add a field for account edit link.
  $data['ledger_account']['edit_account'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the account.'),
      'handler' => 'ledger_account_handler_field_link_edit',
    ),
  );

  // Add a field for account delete link.
  $data['ledger_account']['delete_account'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the account.'),
      'handler' => 'ledger_account_handler_field_link_delete',
    ),
  );

  // Add a field for common account operations. This is just a combination of Edit, and Delete fields above.
  $data['ledger_account']['account_ops'] = array(
    'field' => array(
      'title' => t('Operations'),
      'help' => t('Links to various account operations.'),
      'handler' => 'ledger_account_handler_field_operations',
    ),
  );
}