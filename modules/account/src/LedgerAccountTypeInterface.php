<?php

namespace Drupal\ledger_account;

use Drupal\Core\Config\Entity\ConfigEntityInterface;

/**
 * Provides an interface for defining Ledger Account type entities.
 */
interface LedgerAccountTypeInterface extends ConfigEntityInterface {

  /**
   * Returns the vocabulary hierarchy.
   *
   * @return int
   *   The vocabulary hierarchy.
   */
  public function getType();

  /**
   * Returns the vocabulary hierarchy.
   *
   * @return string $type
   *   The fundamental account type. Must be one of the following:
   *     - asset
   *     - equity
   *     - expense
   *     - income
   *     - liability
   *     - undefined
   */
  public function setType($type);

}
