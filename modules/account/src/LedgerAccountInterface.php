<?php

namespace Drupal\ledger_account;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\user\EntityOwnerInterface;
use Drupal\Core\Entity\EntityChangedInterface;

/**
 * Provides an interface defining an account entity type.
 */
interface LedgerAccountInterface extends ContentEntityInterface, EntityOwnerInterface, EntityChangedInterface {

  /**
   * Gets the account title.
   *
   * @return string
   *   Title of the account.
   */
  public function getTitle();

  /**
   * Sets the account title.
   *
   * @param string $title
   *   The account title.
   *
   * @return \Drupal\ledger_account\LedgerAccountInterface
   *   The called account entity.
   */
  public function setTitle($title);

  /**
   * Gets the account creation timestamp.
   *
   * @return int
   *   Creation timestamp of the account.
   */
  public function getCreatedTime();

  /**
   * Sets the account creation timestamp.
   *
   * @param int $timestamp
   *   The account creation timestamp.
   *
   * @return \Drupal\ledger_account\LedgerAccountInterface
   *   The called account entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Returns the account status.
   *
   * @return bool
   *   TRUE if the account is enabled, FALSE otherwise.
   */
  public function isEnabled();

  /**
   * Sets the account status.
   *
   * @param bool $status
   *   TRUE to enable this account, FALSE to disable.
   *
   * @return \Drupal\ledger_account\LedgerAccountInterface
   *   The called account entity.
   */
  public function setStatus($status);

}
