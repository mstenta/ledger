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
}
