<?php

/**
 * @file
 * Ledger Account Entry Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_account_entry_views_data_alter(&$data) {

  // Override the account entry value's field handler.
  $data['field_data_ledger_value']['ledger_value']['field']['handler'] = 'ledger_handler_field_value';
}

