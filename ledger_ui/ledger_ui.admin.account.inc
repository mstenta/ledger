<?php

/**
 * @file
 * Ledger account admin
 */

/**
 * Wrapper function for the ledger_ui_account_form that serves as a page callback.
 */
function ledger_ui_account_form_wrapper($account) {
  
  // Create the breadcrumb for the page
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Ledger'), 'ledger'),
    l(t('Accounts'), 'ledger/accounts'),
  );
  drupal_set_breadcrumb($breadcrumb);
  
  // Display the ledger account add form.
  return drupal_get_form('ledger_account_form', $account, 'add');
}

/**
 * Generates the ledger account editing form.
 */
function ledger_account_form($form, &$form_state, $account, $op = 'edit') {
  
  // If it's a clone, add "(cloned)" to the end of the account name by default.
  if ($op == 'clone') {
    $account->name .= ' (cloned)';
  }
  
  // Account name
  $form['name'] = array(
    '#title' => t('Account name'),
    '#type' => 'textfield',
    '#default_value' => $account->name,
    '#description' => t('The name of the account.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  
  // Account description
  $form['description'] = array(
    '#title' => t('Description'),
    '#type' => 'textfield',
    '#default_value' => $account->description,
    '#description' => t('A brief description of the account.'),
    '#size' => 50,
  );
  
  // Account type
  $form['type'] = array(
    '#title' => t('Account type'),
    '#type' => 'textfield',
    '#default_value' => $account->type,
    '#description' => t('The account type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  
  // Parent account ID
  /**
   * @todo
   *   Dropdown of available accounts of the same account type.
   */
  $form['pid'] = array(
    '#title' => t('Parent account ID'),
    '#type' => 'textfield',
    '#default_value' => $account->pid,
    '#description' => t('The parent account\'s ID.'),
    '#size' => 30,
  );
  
  // Form actions
  $form['actions'] = array('#type' => 'actions');
  
  // Submit button
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save account'),
    '#weight' => 40,
  );
  
  // If we're not adding or cloning an account, show the delete button.
  if ($op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete account'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('ledger_account_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Form API submit callback for the ledger account form.
 */
function ledger_account_form_submit(&$form, &$form_state) {
  
  // Build a new account object
  $account = ledger_account_new($form_state['values']);
  
  // Save and go back.
  $account->save();
}

/**
 * Form API submit callback for the ledger account delete button.
 */
function ledger_account_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/ledger/accounts/' . $form_state['ledger_account']->aid . '/delete';
}