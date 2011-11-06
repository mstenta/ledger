<?php

/**
 * @file
 * Ledger transaction admin
 */

/**
 * Wrapper function for the ledger_ui_transaction_form that serves as a page callback.
 */
function ledger_ui_transaction_form_wrapper($transaction) {
  
  // Create the breadcrumb for the page
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Ledger'), 'ledger'),
    l(t('Transactions'), 'ledger/transactions'),
  );
  drupal_set_breadcrumb($breadcrumb);
  
  // Display the ledger transaction add form.
  return drupal_get_form('ledger_transaction_form', $transaction, 'add');
}

/**
 * Generates the ledger transaction editing form.
 */
function ledger_transaction_form($form, &$form_state, $transaction, $op = 'edit') {
  
  // If it's a clone, add "(cloned)" to the end of the transaction description by default.
  if ($op == 'clone') {
    $transaction->description .= ' (cloned)';
  }
  
  // Transaction description
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => $transaction->description,
    '#description' => t('A brief description of the transaction.'),
    '#required' => TRUE,
    '#size' => 50,
  );
  
  // Timestamp
  $form['timestamp'] = array(
    '#title' => t('Timestamp'),
    '#type' => 'textfield',
    '#default_value' => $transaction->timestamp,
    '#description' => t('The timestamp of the transaction.'),
    '#required' => TRUE,
    '#size' => 10,
  );
  
  // Add the field related form elements.
  $form_state['ledger_transaction'] = $transaction;
  field_attach_form('ledger_transaction', $transaction, $form, $form_state);
  
  // Form actions
  $form['actions'] = array('#type' => 'actions');
  
  // Submit button
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save transaction'),
    '#weight' => 40,
  );
  
  // If we're not adding or cloning a transaction, show the delete button.
  if ($op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete transaction'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('ledger_transaction_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Form API submit callback for the ledger transaction form.
 */
function ledger_transaction_form_submit(&$form, &$form_state) {
  
  // Build a new transaction object
  $transaction = ledger_transaction_new($form_state['values']);
  
  // Save and go back.
  $transaction->save();
  $form_state['redirect'] = 'ledger/transactions';
}

/**
 * Form API submit callback for the ledger transaction delete button.
 */
function ledger_transaction_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'ledger/transactions/' . $form_state['ledger_transaction']->tid . '/delete';
}