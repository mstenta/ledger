<?php

/**
 * @file
 * Ledger account admin
 */

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
    '#default_value' => 0,
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
  $account = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $account->save();
  $form_state['redirect'] = 'ledger/accounts';
}

/**
 * Form API submit callback for the ledger account delete button.
 */
function ledger_account_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'ledger/accounts' . $form_state['ledger_account']->aid . '/delete';
}