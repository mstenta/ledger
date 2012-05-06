<?php

/**
 * @file
 * Ledger Account Entry Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_account_entry_views_data_alter(&$data) {

  // Add a field for the calculated account entry value.
  $data['ledger_account_entry']['value'] = array(
    'field' => array(
      'title' => t('Value'),
      'help' => t('The value of the account entry.'),
      'handler' => 'ledger_account_entry_handler_field_value',
      'float' => TRUE,
    ),
  );

  // Add a field for the account balance at the time of the account entry.
  $data['ledger_account_entry']['balance'] = array(
    'field' => array(
      'title' => t('Balance'),
      'help' => t('The balance of the account at the time of the account entry.'),
      'handler' => 'ledger_account_entry_handler_field_balance',
      'float' => TRUE,
    ),
  );

  // Add a field for the calculated account balance.
  $data['ledger_account']['balance'] = array(
    'field' => array(
      'title' => t('Balance'),
      'help' => t('The current balance of the account.'),
      'handler' => 'ledger_account_handler_field_balance',
      'float' => TRUE,
    ),
  );

  // Override the default transaction timestamp field and sort handler to also sort by account entry id.
  $data['ledger_transaction']['timestamp']['field']['handler'] = 'ledger_transaction_handler_field_timestamp';
  $data['ledger_transaction']['timestamp']['sort']['handler'] = 'ledger_transaction_handler_sort_timestamp';
}