<?php

/**
 * @file
 * Ledger Budget Views data.
 */

/**
 * Implementations hook_views_data_alter().
 */
function ledger_budget_views_data_alter(&$data) {

  // Replace the budget description field handler with one that provides a "Link this field to" option.
  $data['ledger_budget']['description']['field']['handler'] = 'ledger_budget_handler_field';

  // Add a field for the calculated budget value.
  $data['ledger_budget']['value'] = array(
    'field' => array(
      'title' => t('Value'),
      'help' => t('The value of the budgeted transaction.'),
      'handler' => 'ledger_budget_handler_field_value',
      'float' => TRUE,
    ),
  );

  // Add a field for budget view link.
  $data['ledger_budget']['view_budget'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the budget.'),
      'handler' => 'ledger_budget_handler_field_link',
    ),
  );

  // Add a field for budget edit link.
  $data['ledger_budget']['edit_budget'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the budget.'),
      'handler' => 'ledger_budget_handler_field_link_edit',
    ),
  );

  // Add a field for budget delete link.
  $data['ledger_budget']['delete_budget'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the budget.'),
      'handler' => 'ledger_budget_handler_field_link_delete',
    ),
  );

  // Add a field for common budget operations. This is just a combination of Edit, and Delete fields above.
  $data['ledger_budget']['budget_ops'] = array(
    'field' => array(
      'title' => t('Operations'),
      'help' => t('Links to various budget operations.'),
      'handler' => 'ledger_budget_handler_field_operations',
    ),
  );
}