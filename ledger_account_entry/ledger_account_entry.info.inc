<?php

/**
 * @file
 * Ledger Account Entry property info
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_account_entry_entity_property_info() {
  $info = array();

  // Add meta-data about the account entry properties.
  $account_entry = &$info['ledger_account_entry']['properties'];

  $account_entry['eid'] = array(
    'type' => 'integer',
    'label' => t('Account entry ID'),
    'description' => t('The unique ID of the ledger account entry.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'eid',
  );
  $account_entry['account'] = array(
    'type' => 'ledger_account',
    'label' => t('Account'),
    'description' => t('The account that the entry is posted to.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'aid',
  );
  $account_entry['transaction'] = array(
    'type' => 'ledger_transaction',
    'label' => t('Transaction'),
    'description' => t('The transaction that the entry is posted to.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'tid',
  );
  $account_entry['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of the account entry.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'description',
  );

  return $info;
}