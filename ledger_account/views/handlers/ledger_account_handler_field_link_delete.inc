<?php

/**
 * @file
 * Field handler to present a link to delete an account.
 */
class ledger_account_handler_field_link_delete extends ledger_account_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this account.
    $account = ledger_account_load($this->get_value($values, 'aid'));
    if (!ledger_account_access('update', $account)) {
      return;
    }

    // Assemble the link options.
    $options = array();
    if (!empty($this->options['destination'])) {
      $options['query']['destination'] = current_path();
    }

    // Load the link text, if it is defined in the options, otherwise just use "delete".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');

    // Return the text as a link to the account delete page.
    return l($text, 'ledger/account/' . $account->aid . '/delete', $options);
  }
}

