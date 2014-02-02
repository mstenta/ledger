<?php

/**
 * @file
 * Field handler to present an account edit link.
 */
class ledger_account_handler_field_link_edit extends ledger_account_handler_field_link {

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

    // Load the link text, if it is defined in the options, otherwise just use "edit".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    // Return the text as a link to the account edit page.
    return l($text, 'ledger/account/' . $account->aid . '/edit', $options);
  }
}

