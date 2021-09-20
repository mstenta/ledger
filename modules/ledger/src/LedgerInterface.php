<?php

namespace Drupal\ledger_ledger;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\user\EntityOwnerInterface;
use Drupal\Core\Entity\EntityChangedInterface;

/**
 * Provides an interface defining a ledger entity type.
 */
interface LedgerInterface extends ContentEntityInterface, EntityOwnerInterface, EntityChangedInterface {

  /**
   * Gets the ledger title.
   *
   * @return string
   *   Title of the ledger.
   */
  public function getTitle();

  /**
   * Sets the ledger title.
   *
   * @param string $title
   *   The ledger title.
   *
   * @return \Drupal\ledger_ledger\LedgerInterface
   *   The called ledger entity.
   */
  public function setTitle($title);

  /**
   * Gets the ledger creation timestamp.
   *
   * @return int
   *   Creation timestamp of the ledger.
   */
  public function getCreatedTime();

  /**
   * Sets the ledger creation timestamp.
   *
   * @param int $timestamp
   *   The ledger creation timestamp.
   *
   * @return \Drupal\ledger_ledger\LedgerInterface
   *   The called ledger entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Returns the ledger status.
   *
   * @return bool
   *   TRUE if the ledger is enabled, FALSE otherwise.
   */
  public function isEnabled();

  /**
   * Sets the ledger status.
   *
   * @param bool $status
   *   TRUE to enable this ledger, FALSE to disable.
   *
   * @return \Drupal\ledger_ledger\LedgerInterface
   *   The called ledger entity.
   */
  public function setStatus($status);

}
