<?php

/**
 * @file
 * Ledger Budget property info
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_budget_entity_property_info() {
  $info = array();

  // Add meta-data about the budget properties.
  $budget = &$info['ledger_budget']['properties'];

  $budget['bid'] = array(
    'type' => 'integer',
    'label' => t('Budget ID'),
    'description' => t('The unique ID of the ledger budget.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'bid',
  );
  $budget['budget_account'] = array(
    'type' => 'ledger_account',
    'label' => t('Budget Account ID'),
    'description' => t('The account ID of the budget account'),
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'schema field' => 'budget_aid',
  );
  $budget['target_account'] = array(
    'type' => 'ledger_account',
    'label' => t('Target Account ID'),
    'description' => t('The account ID of the target account'),
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'schema field' => 'target_aid',
  );
  $budget['effective'] = array(
    'type' => 'date',
    'label' => t('Effective'),
    'description' => t('Timestamp for when the budget takes effect'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'effective',
  );
  $budget['expires'] = array(
    'type' => 'date',
    'label' => t('Expires'),
    'description' => t('Timestamp for when the budget expires'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'expires',
  );
  $budget['repeat_every'] = array(
    'type' => 'integer',
    'label' => t('Repeat Every'),
    'description' => t('Repeat every X {repeat_units}'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'repeat_every',
  );
  $budget['repeat_unit'] = array(
    'label' => t('Repeat Unit'),
    'description' => t('Repeat every X {repeat_units}'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'repeat_unit',
  );
  $budget['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of the budget.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'description',
  );

  return $info;
}

