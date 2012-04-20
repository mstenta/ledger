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
}

/**
 * Implements hook_views_query_alter().
 */
function ledger_account_entry_views_query_alter(&$view, &$query) {

  /**
   * If the View includes the account entry balance field, add a sort by account entry id.
   * We do this because the account entry balances are calculated in a specific order (timestamp, eid),
   * so we need to make sure they are displayed in the same order. The following code checks to see if
   * a) the balance field is present, and b) the View is being sorted by timestamp. If so, it adds a sort
   * by account entry id, in the same direction (ASC/DESC) as the timestamp.
   *   See: ledger_account_entry_calculate_balances().
   *   See: ledger_account_entry_handler_field_balance class.
   *
   * @todo
   *   This is looking for a special variable in the $query object set by our ledger_account_entry_handler_field_balance field handler.
   *   It would be better if there was a reliable way of checking to see if that field exists in the View.
   */
  if (isset($query->ledger_account_entry_balance)) {

    // Search the existing "ORDER BY"s for the transaction timestamp.
    /**
     * @todo
     *   This looks for an orderby field specifically called 'ledger_transaction_timestamp', which should work in most cases.
     *   It would be better if there was a reliable way of checking to see if the View is sorted by timestamp.
     */
    $timestamp_sort = FALSE;
    foreach ($query->orderby as $orderby) {
      if ($orderby['field'] == 'ledger_transaction_timestamp') {
        $timestamp_sort = $orderby['direction'];
      }
    }

    // Add an ORDER BY to sort by account entry id, in addition to timestamp, with the same direction (ASC/DESC).
    /**
     * @todo
     *   This assumes that the special variable in the $query object (see above) has the ledger_account_entry's table alias.
     *   It would be better if there was a reliable way to determine the table's alias within this function.
     */
    if ($timestamp_sort) {
      $query->add_orderby(NULL, NULL, $timestamp_sort, $query->field_aliases[$query->ledger_account_entry_balance['table_alias']]['eid']);
    }
  }
}