<?php

/**
 * @file
 * Field handler to present an account edit link.
 */
class ledger_account_handler_field_link_edit extends ledger_account_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this account.
    $account = ledger_account_new();
    $account->aid = $this->get_value($values, 'aid');
    if (!ledger_account_access('update', $account)) {
      return;
    }

    // Load the link text, if it is defined in the options, otherwise just use "edit".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    // Return the text as a link to the account edit page.
    return l($text, 'admin/ledger/accounts/' . $account->aid . '/edit');
  }
}
