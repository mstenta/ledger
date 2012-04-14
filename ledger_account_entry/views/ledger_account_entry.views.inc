<?php

/**
 * @file
 * Ledger Account Entry Views data.
 */

/**
 * Implementations hook_views_data_alter().
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

  // Add a field for displaying the running account balance at the time of an account entry.
  $data['ledger_account_entry']['account_balance'] = array(
    'field' => array(
      'title' => t('Running account balance'),
      'help' => t('Display the running balance of the account at the time of an account entry.'),
      'handler' => 'ledger_account_entry_handler_field_account_balance',
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
}