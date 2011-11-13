<?php

/**
 * Field handler to present an account edit link.
 */
class ledger_account_handler_field_link_edit extends ledger_account_handler_field_link {
  function render($values) {
    
    // Ensure the user has access to edit this order.
    $account = ledger_account_new();
    $account->aid = $this->get_value($values, 'aid');

    if (!ledger_account_access('update', $account)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return l($text, 'admin/ledger/accounts/' . $account->aid . '/edit', array('query' => drupal_get_destination()));
  }
}
