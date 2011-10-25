<?php

/**
 * @file
 * Ledger callbacks
 */

/**
 * Callback for setting ledger account properties.
 */
function ledger_account_set_properties($account, $name, $value) {
  if ($name == 'parent') {
    $account->pid = $value;
  }
}

/**
 * Callback for getting ledger account properties.
 */
function ledger_account_get_properties($account, array $options, $name, $entity_type) {
  if ($name == 'parent') {
    return $account->pid;
  }
}

/**
 * Callback for setting ledger transaction properties.
 */
function ledger_transaction_set_properties($transaction, $name, $value) {
  if ($name == 'credit_account') {
    $transaction->credit_aid = $value;
  }
  else if ($name == 'debit_account') {
    $transaction->debit_aid = $value;
  }
}

/**
 * Callback for getting ledger transaction properties.
 */
function ledger_transaction_get_properties($transaction, array $options, $name, $entity_type) {
  if ($name == 'credit_account') {
    return $transaction->credit_aid;
  }
  else if ($name == 'debit_account') {
    return $transaction->debit_aid;
  }
}