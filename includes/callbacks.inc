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