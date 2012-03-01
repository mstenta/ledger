<?php

/**
 * @file
 * Field handler to present a list of links to account operations.
 */
class ledger_account_handler_field_operations extends ledger_account_handler_field_link {

  // Alter the field options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent form.
    parent::options_form($form, $form_state);

    // Unset the 'text' field that was defined by the parent class.
    unset($form['text']);
  }

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this account.
    $account = ledger_account_new();
    $account->aid = $this->get_value($values, 'aid');
    if (!ledger_account_access('update', $account)) {
      return;
    }

    // Define the operations to include.
    $ops = array(
      l(t('Edit'), 'admin/ledger/accounts/' . $account->aid . '/edit'),
      l(t('Delete'), 'admin/ledger/accounts/' . $account->aid . '/delete'),
    );

    // Assemble the list of operations.
    return implode(' | ', $ops);
  }
}
