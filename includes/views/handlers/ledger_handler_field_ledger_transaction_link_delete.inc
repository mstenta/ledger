<?php

/**
 * Field handler to present a link to delete a transaction.
 */
class ledger_handler_field_ledger_transaction_link_delete extends ledger_handler_field_ledger_transaction_link {
  function render($values) {
    
    // Ensure the user has access to edit this order.
    $transaction = ledger_transaction_new();
    $transaction->tid = $this->get_value($values, 'tid');

    if (!ledger_transaction_access('update', $transaction)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, 'ledger/transactions/' . $transaction->tid . '/delete', array('query' => drupal_get_destination()));
  }
}
