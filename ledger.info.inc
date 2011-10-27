<?php

/**
 * @file
 * Ledger
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_entity_property_info() {
  $info = array();
  
  // Add meta-data about the account properties.
  $account = &$info['ledger_account']['properties'];

  $account['aid'] = array(
    'type' => 'integer',
    'label' => t('Account ID'),
    'description' => t('The unique ID of the ledger account.'),
    'schema field' => 'aid',
  );
  $account['parent'] = array(
    'type' => 'ledger_account',
    'label' => t('Parent Account'),
    'description' => t('The parent account in the ledger.'),
    'getter callback' => 'ledger_account_get_properties',
    'setter callback' => 'ledger_account_set_properties',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'pid',
  );
  $account['name'] = array(
    'label' => t('Name'),
    'description' => t('The name of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'schema field' => 'name',
    'required' => TRUE,
  );
  $account['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'schema field' => 'description',
  );
  $account['type'] = array(
    'label' => t('Account type'),
    'description' => t('The type of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'type',
  );

  // Add meta-data about the transaction properties.
  $transaction = &$info['ledger_transaction']['properties'];
  
  $transaction['tid'] = array(
    'type' => 'integer',
    'label' => t('Transaction ID'),
    'description' => t('The unique ID of the ledger transaction.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'tid',
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