<?php

namespace Drupal\ledger;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface for defining Ledger entities.
 *
 * @ingroup ledger
 */
interface LedgerInterface extends ContentEntityInterface, EntityChangedInterface, EntityOwnerInterface {

  // Add get/set methods for your configuration properties here.

  /**
   * Gets the Ledger name.
   *
   * @return string
   *   Name of the Ledger.
   */
  public function getName();

  /**
   * Sets the Ledger name.
   *
   * @param string $name
   *   The Ledger name.
   *
   * @return \Drupal\ledger\LedgerInterface
   *   The called Ledger entity.
   */
  public function setName($name);

  /**
   * Gets the Ledger creation timestamp.
   *
   * @return int
   *   Creation timestamp of the Ledger.
   */
  public function getCreatedTime();

  /**
   * Sets the Ledger creation timestamp.
   *
   * @param int $timestamp
   *   The Ledger creation timestamp.
   *
   * @return \Drupal\ledger\LedgerInterface
   *   The called Ledger entity.
   */
  public function setCreatedTime($timestamp);

  /**
   * Returns the Ledger published status indicator.
   *
   * Unpublished Ledger are only visible to restricted users.
   *
   * @return bool
   *   TRUE if the Ledger is published.
   */
  public function isPublished();

  /**
   * Sets the published status of a Ledger.
   *
   * @param bool $published
   *   TRUE to set this Ledger to published, FALSE to set it to unpublished.
   *
   * @return \Drupal\ledger\LedgerInterface
   *   The called Ledger entity.
   */
  public function setPublished($published);

}
