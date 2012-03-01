<?php

/**
 * @file
 * Field handler to present a transaction edit link.
 */
class ledger_transaction_handler_field_link_edit extends ledger_transaction_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this order.
    $transaction = ledger_transaction_new();
    $transaction->tid = $this->get_value($values, 'tid');
    if (!ledger_transaction_access('update', $transaction)) {
      return;
    }

    // Load the link text, if it is defined in the options, otherwise just use "edit".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    // Return the text as a link to the transaction edit page.
    return l($text, 'admin/ledger/transactions/' . $transaction->tid . '/edit', array('query' => drupal_get_destination()));
  }
}
