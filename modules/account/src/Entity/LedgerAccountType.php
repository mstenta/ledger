<?php

namespace Drupal\ledger_account\Entity;

use Drupal\Core\Config\Entity\ConfigEntityBundleBase;

/**
 * Defines the Account type configuration entity.
 *
 * @ConfigEntityType(
 *   id = "ledger_account_type",
 *   label = @Translation("Account type"),
 *   handlers = {
 *     "form" = {
 *       "add" = "Drupal\ledger_account\Form\LedgerAccountTypeForm",
 *       "edit" = "Drupal\ledger_account\Form\LedgerAccountTypeForm",
 *       "delete" = "Drupal\Core\Entity\EntityDeleteForm",
 *     },
 *     "list_builder" = "Drupal\ledger_account\LedgerAccountTypeListBuilder",
 *     "route_provider" = {
 *       "html" = "Drupal\Core\Entity\Routing\AdminHtmlRouteProvider",
 *     }
 *   },
 *   admin_permission = "administer account types",
 *   bundle_of = "ledger_account",
 *   config_prefix = "ledger_account_type",
 *   entity_keys = {
 *     "id" = "id",
 *     "label" = "label",
 *     "uuid" = "uuid"
 *   },
 *   links = {
 *     "add-form" = "/admin/structure/ledger_account_types/add",
 *     "edit-form" = "/admin/structure/ledger_account_types/manage/{ledger_account_type}",
 *     "delete-form" = "/admin/structure/ledger_account_types/manage/{ledger_account_type}/delete",
 *     "collection" = "/admin/structure/ledger_account_types"
 *   },
 *   config_export = {
 *     "id",
 *     "label",
 *     "uuid",
 *   }
 * )
 */
class LedgerAccountType extends ConfigEntityBundleBase {

  /**
   * The machine name of this account type.
   *
   * @var string
   */
  protected $id;

  /**
   * The human-readable name of the account type.
   *
   * @var string
   */
  protected $label;

}
