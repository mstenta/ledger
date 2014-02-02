<?php

/**
 * @file
 * Ledger Transaction property info
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_transaction_entity_property_info() {
  $info = array();

  // Add meta-data about the transaction properties.
  $transaction = &$info['ledger_transaction']['properties'];

  $transaction['tid'] = array(
    'type' => 'integer',
    'label' => t('Transaction ID'),
    'description' => t('The unique ID of the ledger transaction.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'tid',
  );
  $transaction['book'] = array(
    'type' => 'ledger_book',
    'label' => t('Book'),
    'description' => t('The book that the transaction is assigned to.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'bid',
  );
  $transaction['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of the transaction.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'description',
  );
  $transaction['timestamp'] = array(
    'type' => 'date',
    'label' => t('Timestamp'),
    'description' => t('The date the transaction was posted.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'timestamp',
  );

  return $info;
}

