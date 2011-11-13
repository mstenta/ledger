<?php

/**
 * Field handler to present a link to delete an account.
 */
class ledger_account_handler_field_link_delete extends ledger_account_handler_field_link {
  function render($values) {
    
    // Ensure the user has access to edit this order.
    $account = ledger_account_new();
    $account->aid = $this->get_value($values, 'aid');

    if (!ledger_account_access('update', $account)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, 'admin/ledger/accounts/' . $account->aid . '/delete', array('query' => drupal_get_destination()));
  }
}
