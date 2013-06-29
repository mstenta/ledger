<?php

/**
 * @file
 * Ledger Period Views hooks.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_period_views_data_alter(&$data) {

  // Define Views integration for the {ledger_account_entry_balance} table.
  $data['ledger_account_entry_balance']['table'] = array(
    'group' => t('Account entry'),
    'join' => array(
      'ledger_account_entry' => array(
        'left_field' => 'eid',
        'field' => 'eid',
      ),
    ),
  );

  // Add a field for the account balance at the time of the account entry.
  $data['ledger_account_entry_balance']['balance'] = array(
    'field' => array(
      'title' => t('Balance'),
      'help' => t('The balance of the account at the time of the account entry.'),
      'handler' => 'ledger_account_entry_handler_field_balance',
      'float' => TRUE,
    ),
  );

  // Add a field for the current account balance.
  $data['ledger_account']['balance'] = array(
    'field' => array(
      'title' => t('Balance'),
      'help' => t('The current balance of the account.'),
      'handler' => 'ledger_account_handler_field_balance',
      'float' => TRUE,
    ),
  );

  // Override the default transaction timestamp field and sort handler to also sort by account entry id when an account entry balance is present.
  $data['ledger_transaction']['timestamp']['field']['handler'] = 'ledger_transaction_handler_field_timestamp';
  $data['ledger_transaction']['timestamp']['sort']['handler'] = 'ledger_transaction_handler_sort_timestamp';
}

