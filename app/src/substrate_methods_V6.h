/*******************************************************************************
*  (c) 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V6.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V6 0
#define PD_CALL_BABE_V6 1
#define PD_CALL_TIMESTAMP_V6 2
#define PD_CALL_INDICES_V6 3
#define PD_CALL_BALANCES_V6 4
#define PD_CALL_IDENTITY_V6 6
#define PD_CALL_AUTHORSHIP_V6 7
#define PD_CALL_CDDSERVICEPROVIDERS_V6 38
#define PD_CALL_STAKING_V6 8
#define PD_CALL_OFFENCES_V6 9
#define PD_CALL_SESSION_V6 10
#define PD_CALL_FINALITYTRACKER_V6 11
#define PD_CALL_GRANDPA_V6 12
#define PD_CALL_IMONLINE_V6 13
#define PD_CALL_AUTHORITYDISCOVERY_V6 14
#define PD_CALL_RANDOMNESSCOLLECTIVEFLIP_V6 15
#define PD_CALL_SUDO_V6 17
#define PD_CALL_MULTISIG_V6 18
#define PD_CALL_CONTRACTS_V6 20
#define PD_CALL_TREASURY_V6 21
#define PD_CALL_POLYMESHCOMMITTEE_V6 22
#define PD_CALL_COMMITTEEMEMBERSHIP_V6 23
#define PD_CALL_PIPS_V6 24
#define PD_CALL_TECHNICALCOMMITTEE_V6 25
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V6 26
#define PD_CALL_UPGRADECOMMITTEE_V6 27
#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_V6 28
#define PD_CALL_ASSET_V6 29
#define PD_CALL_BRIDGE_V6 31
#define PD_CALL_COMPLIANCEMANAGER_V6 32
#define PD_CALL_SETTLEMENT_V6 36
#define PD_CALL_STO_V6 37
#define PD_CALL_STATISTICS_V6 39
#define PD_CALL_PROTOCOLFEE_V6 40
#define PD_CALL_UTILITY_V6 41
#define PD_CALL_PORTFOLIO_V6 42
#define PD_CALL_CONFIDENTIAL_V6 43
#define PD_CALL_SCHEDULER_V6 45
#define PD_CALL_CORPORATEACTION_V6 46
#define PD_CALL_CORPORATEBALLOT_V6 47
#define PD_CALL_CAPITALDISTRIBUTION_V6 48
#define PD_CALL_CHECKPOINT_V6 49

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_ASSET_CONTROLLER_TRANSFER_V6 22
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_BalanceNoSymbol_t value;
    pd_PortfolioId_V6_t from_portfolio;
} pd_asset_controller_transfer_V6_t;

#define PD_CALL_SETTLEMENT_CHANGE_RECEIPT_VALIDITY_V6 13
typedef struct {
    pd_u64_t receipt_uid;
    pd_bool_t validity;
} pd_settlement_change_receipt_validity_V6_t;

#define PD_CALL_STO_CREATE_FUNDRAISER_V6 0
typedef struct {
    pd_PortfolioId_V6_t offering_portfolio;
    pd_Ticker_V6_t offering_asset;
    pd_PortfolioId_V6_t raising_portfolio;
    pd_Ticker_V6_t raising_asset;
    pd_VecPriceTier_V6_t tiers;
    pd_u64_t venue_id;
    pd_OptionMoment_V6_t start;
    pd_OptionMoment_V6_t end;
    pd_BalanceNoSymbol_t minimum_investment;
    pd_FundraiserName_V6_t fundraiser_name;
} pd_sto_create_fundraiser_V6_t;

#define PD_CALL_STO_INVEST_V6 1
typedef struct {
    pd_PortfolioId_V6_t investment_portfolio;
    pd_PortfolioId_V6_t funding_portfolio;
    pd_Ticker_V6_t offering_asset;
    pd_u64_t fundraiser_id;
    pd_BalanceNoSymbol_t purchase_amount;
    pd_OptionBalance_t max_price;
    pd_OptionReceiptDetails_V6_t receipt;
} pd_sto_invest_V6_t;

#define PD_CALL_STO_FREEZE_FUNDRAISER_V6 2
typedef struct {
    pd_Ticker_V6_t offering_asset;
    pd_u64_t fundraiser_id;
} pd_sto_freeze_fundraiser_V6_t;

#define PD_CALL_STO_UNFREEZE_FUNDRAISER_V6 3
typedef struct {
    pd_Ticker_V6_t offering_asset;
    pd_u64_t fundraiser_id;
} pd_sto_unfreeze_fundraiser_V6_t;

#define PD_CALL_STO_MODIFY_FUNDRAISER_WINDOW_V6 4
typedef struct {
    pd_Ticker_V6_t offering_asset;
    pd_u64_t fundraiser_id;
    pd_Moment_V6_t start;
    pd_OptionMoment_V6_t end;
} pd_sto_modify_fundraiser_window_V6_t;

#define PD_CALL_STO_STOP_V6 5
typedef struct {
    pd_Ticker_V6_t offering_asset;
    pd_u64_t fundraiser_id;
} pd_sto_stop_V6_t;

#define PD_CALL_CONFIDENTIAL_ADD_RANGE_PROOF_V6 0
typedef struct {
    pd_IdentityId_V6_t target_id;
    pd_Ticker_V6_t ticker;
    pd_u64_t secret_value;
} pd_confidential_add_range_proof_V6_t;

#define PD_CALL_CONFIDENTIAL_ADD_VERIFY_RANGE_PROOF_V6 1
typedef struct {
    pd_IdentityId_V6_t target;
    pd_IdentityId_V6_t prover;
    pd_Ticker_V6_t ticker;
} pd_confidential_add_verify_range_proof_V6_t;

#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
    pd_asset_controller_transfer_V6_t asset_controller_transfer_V6;
    pd_settlement_change_receipt_validity_V6_t settlement_change_receipt_validity_V6;
    pd_sto_create_fundraiser_V6_t sto_create_fundraiser_V6;
    pd_sto_invest_V6_t sto_invest_V6;
    pd_sto_freeze_fundraiser_V6_t sto_freeze_fundraiser_V6;
    pd_sto_unfreeze_fundraiser_V6_t sto_unfreeze_fundraiser_V6;
    pd_sto_modify_fundraiser_window_V6_t sto_modify_fundraiser_window_V6;
    pd_sto_stop_V6_t sto_stop_V6;
    pd_confidential_add_range_proof_V6_t confidential_add_range_proof_V6;
    pd_confidential_add_verify_range_proof_V6_t confidential_add_verify_range_proof_V6;
#endif
} pd_MethodBasic_V6_t;

#define PD_CALL_BALANCES_TRANSFER_V6 0
typedef struct {
    pd_LookupSource_V6_t dest;
    pd_CompactBalance_t value;
} pd_balances_transfer_V6_t;

#define PD_CALL_BALANCES_TRANSFER_WITH_MEMO_V6 1
typedef struct {
    pd_LookupSource_V6_t dest;
    pd_CompactBalance_t value;
    pd_OptionMemo_V6_t memo;
} pd_balances_transfer_with_memo_V6_t;

#define PD_CALL_STAKING_VALIDATE_V6 4
typedef struct {
    pd_ValidatorPrefs_V6_t prefs;
} pd_staking_validate_V6_t;

#define PD_CALL_STAKING_NOMINATE_V6 5
typedef struct {
    pd_VecLookupSource_V6_t targets;
} pd_staking_nominate_V6_t;

#define PD_CALL_STAKING_CHILL_V6 6
typedef struct {
} pd_staking_chill_V6_t;

#define PD_CALL_STAKING_SET_PAYEE_V6 7
typedef struct {
    pd_RewardDestination_V6_t payee;
} pd_staking_set_payee_V6_t;

#define PD_CALL_SESSION_SET_KEYS_V6 0
typedef struct {
    pd_Keys_V6_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V6_t;

#define PD_CALL_SESSION_PURGE_KEYS_V6 1
typedef struct {
} pd_session_purge_keys_V6_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V6 0
typedef struct {
    pd_Perbill_V6_t _ratio;
} pd_system_fill_block_V6_t;

#define PD_CALL_SYSTEM_REMARK_V6 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V6_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V6 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V6_t;

#define PD_CALL_SYSTEM_SET_CODE_V6 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V6_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V6 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V6_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG_V6 5
typedef struct {
    pd_OptionChangesTrieConfiguration_V6_t changes_trie_config;
} pd_system_set_changes_trie_config_V6_t;

#define PD_CALL_SYSTEM_SET_STORAGE_V6 6
typedef struct {
    pd_VecKeyValue_V6_t items;
} pd_system_set_storage_V6_t;

#define PD_CALL_SYSTEM_KILL_STORAGE_V6 7
typedef struct {
    pd_VecKey_V6_t keys;
} pd_system_kill_storage_V6_t;

#define PD_CALL_SYSTEM_KILL_PREFIX_V6 8
typedef struct {
    pd_Key_V6_t prefix;
    pd_u32_t _subkeys;
} pd_system_kill_prefix_V6_t;

#define PD_CALL_SYSTEM_SUICIDE_V6 9
typedef struct {
} pd_system_suicide_V6_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_V6 0
typedef struct {
    pd_EquivocationProof_V6_t equivocation_proof;
    pd_KeyOwnerProof_V6_t key_owner_proof;
} pd_babe_report_equivocation_V6_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED_V6 1
typedef struct {
    pd_EquivocationProof_V6_t equivocation_proof;
    pd_KeyOwnerProof_V6_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_V6_t;

#define PD_CALL_TIMESTAMP_SET_V6 0
typedef struct {
    pd_CompactMoment_V6_t now;
} pd_timestamp_set_V6_t;

#define PD_CALL_INDICES_CLAIM_V6 0
typedef struct {
    pd_AccountIndex_V6_t index;
} pd_indices_claim_V6_t;

#define PD_CALL_INDICES_TRANSFER_V6 1
typedef struct {
    pd_AccountId_V6_t new_;
    pd_AccountIndex_V6_t index;
} pd_indices_transfer_V6_t;

#define PD_CALL_INDICES_FREE_V6 2
typedef struct {
    pd_AccountIndex_V6_t index;
} pd_indices_free_V6_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V6 3
typedef struct {
    pd_AccountId_V6_t new_;
    pd_AccountIndex_V6_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V6_t;

#define PD_CALL_INDICES_FREEZE_V6 4
typedef struct {
    pd_AccountIndex_V6_t index;
} pd_indices_freeze_V6_t;

#define PD_CALL_BALANCES_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE_V6 2
typedef struct {
    pd_CompactBalance_t value;
} pd_balances_deposit_block_reward_reserve_balance_V6_t;

#define PD_CALL_BALANCES_SET_BALANCE_V6 3
typedef struct {
    pd_LookupSource_V6_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V6_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V6 4
typedef struct {
    pd_LookupSource_V6_t source;
    pd_LookupSource_V6_t dest;
    pd_CompactBalance_t value;
} pd_balances_force_transfer_V6_t;

#define PD_CALL_BALANCES_BURN_ACCOUNT_BALANCE_V6 5
typedef struct {
    pd_Balance_t amount;
} pd_balances_burn_account_balance_V6_t;

#define PD_CALL_IDENTITY_REGISTER_DID_V6 0
typedef struct {
    pd_InvestorUid_V6_t uid;
    pd_VecSecondaryKey_V6_t secondary_keys;
} pd_identity_register_did_V6_t;

#define PD_CALL_IDENTITY_CDD_REGISTER_DID_V6 1
typedef struct {
    pd_AccountId_V6_t target_account;
    pd_VecSecondaryKey_V6_t secondary_keys;
} pd_identity_cdd_register_did_V6_t;

#define PD_CALL_IDENTITY_MOCK_CDD_REGISTER_DID_V6 2
typedef struct {
    pd_AccountId_V6_t target_account;
} pd_identity_mock_cdd_register_did_V6_t;

#define PD_CALL_IDENTITY_INVALIDATE_CDD_CLAIMS_V6 3
typedef struct {
    pd_IdentityId_V6_t cdd;
    pd_Moment_V6_t disable_from;
    pd_OptionMoment_V6_t expiry;
} pd_identity_invalidate_cdd_claims_V6_t;

#define PD_CALL_IDENTITY_REMOVE_SECONDARY_KEYS_V6 4
typedef struct {
    pd_VecSignatory_V6_t signers_to_remove;
} pd_identity_remove_secondary_keys_V6_t;

#define PD_CALL_IDENTITY_ACCEPT_PRIMARY_KEY_V6 5
typedef struct {
    pd_u64_t rotation_auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_accept_primary_key_V6_t;

#define PD_CALL_IDENTITY_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION_V6 6
typedef struct {
    pd_bool_t auth_required;
} pd_identity_change_cdd_requirement_for_mk_rotation_V6_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_KEY_V6 7
typedef struct {
    pd_u64_t auth_id;
} pd_identity_join_identity_as_key_V6_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_IDENTITY_V6 8
typedef struct {
    pd_u64_t auth_id;
} pd_identity_join_identity_as_identity_V6_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_KEY_V6 9
typedef struct {
} pd_identity_leave_identity_as_key_V6_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_IDENTITY_V6 10
typedef struct {
    pd_IdentityId_V6_t did;
} pd_identity_leave_identity_as_identity_V6_t;

#define PD_CALL_IDENTITY_ADD_CLAIM_V6 11
typedef struct {
    pd_IdentityId_V6_t target;
    pd_Claim_V6_t claim;
    pd_OptionMoment_V6_t expiry;
} pd_identity_add_claim_V6_t;

#define PD_CALL_IDENTITY_FORWARDED_CALL_V6 12
typedef struct {
    pd_IdentityId_V6_t target_did;
    pd_Proposal_t proposal;
} pd_identity_forwarded_call_V6_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_V6 13
typedef struct {
    pd_IdentityId_V6_t target;
    pd_Claim_V6_t claim;
} pd_identity_revoke_claim_V6_t;

#define PD_CALL_IDENTITY_SET_PERMISSION_TO_SIGNER_V6 14
typedef struct {
    pd_Signatory_V6_t signer;
    pd_Permissions_V6_t permissions;
} pd_identity_set_permission_to_signer_V6_t;

#define PD_CALL_IDENTITY_LEGACY_SET_PERMISSION_TO_SIGNER_V6 15
typedef struct {
    pd_Signatory_V6_t signer;
    pd_LegacyPermissions_V6_t permissions;
} pd_identity_legacy_set_permission_to_signer_V6_t;

#define PD_CALL_IDENTITY_FREEZE_SECONDARY_KEYS_V6 16
typedef struct {
} pd_identity_freeze_secondary_keys_V6_t;

#define PD_CALL_IDENTITY_UNFREEZE_SECONDARY_KEYS_V6 17
typedef struct {
} pd_identity_unfreeze_secondary_keys_V6_t;

#define PD_CALL_IDENTITY_GET_MY_DID_V6 18
typedef struct {
} pd_identity_get_my_did_V6_t;

#define PD_CALL_IDENTITY_GET_CDD_OF_V6 19
typedef struct {
    pd_AccountId_V6_t of;
} pd_identity_get_cdd_of_V6_t;

#define PD_CALL_IDENTITY_ADD_AUTHORIZATION_V6 20
typedef struct {
    pd_Signatory_V6_t target;
    pd_AuthorizationData_V6_t authorization_data;
    pd_OptionMoment_V6_t expiry;
} pd_identity_add_authorization_V6_t;

#define PD_CALL_IDENTITY_REMOVE_AUTHORIZATION_V6 21
typedef struct {
    pd_Signatory_V6_t target;
    pd_u64_t auth_id;
    pd_bool_t _auth_issuer_pays;
} pd_identity_remove_authorization_V6_t;

#define PD_CALL_IDENTITY_ACCEPT_AUTHORIZATION_V6 22
typedef struct {
    pd_u64_t auth_id;
} pd_identity_accept_authorization_V6_t;

#define PD_CALL_IDENTITY_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION_V6 23
typedef struct {
    pd_VecSecondaryKeyWithAuth_V6_t additional_keys;
    pd_Moment_V6_t expires_at;
} pd_identity_add_secondary_keys_with_authorization_V6_t;

#define PD_CALL_IDENTITY_REVOKE_OFFCHAIN_AUTHORIZATION_V6 24
typedef struct {
    pd_Signatory_V6_t signer;
    pd_TargetIdAuthorization_V6_t auth;
} pd_identity_revoke_offchain_authorization_V6_t;

#define PD_CALL_IDENTITY_ADD_INVESTOR_UNIQUENESS_CLAIM_V6 25
typedef struct {
    pd_IdentityId_V6_t target;
    pd_Claim_V6_t claim;
    pd_InvestorZKProofData_V6_t proof;
    pd_OptionMoment_V6_t expiry;
} pd_identity_add_investor_uniqueness_claim_V6_t;

#define PD_CALL_IDENTITY_GC_ADD_CDD_CLAIM_V6 26
typedef struct {
    pd_IdentityId_V6_t target;
    pd_OptionMoment_V6_t expiry;
} pd_identity_gc_add_cdd_claim_V6_t;

#define PD_CALL_IDENTITY_GC_REVOKE_CDD_CLAIM_V6 27
typedef struct {
    pd_IdentityId_V6_t target;
} pd_identity_gc_revoke_cdd_claim_V6_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES_V6 0
typedef struct {
    pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SET_ACTIVE_MEMBERS_LIMIT_V6 0
typedef struct {
    pd_MemberCount_V6_t limit;
} pd_cddserviceproviders_set_active_members_limit_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_DISABLE_MEMBER_V6 1
typedef struct {
    pd_IdentityId_V6_t who;
    pd_OptionMoment_V6_t expiry;
    pd_OptionMoment_V6_t at;
} pd_cddserviceproviders_disable_member_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ADD_MEMBER_V6 2
typedef struct {
    pd_IdentityId_V6_t who;
} pd_cddserviceproviders_add_member_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_REMOVE_MEMBER_V6 3
typedef struct {
    pd_IdentityId_V6_t who;
} pd_cddserviceproviders_remove_member_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SWAP_MEMBER_V6 4
typedef struct {
    pd_IdentityId_V6_t remove;
    pd_IdentityId_V6_t add;
} pd_cddserviceproviders_swap_member_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_RESET_MEMBERS_V6 5
typedef struct {
    pd_VecIdentityId_V6_t members;
} pd_cddserviceproviders_reset_members_V6_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ABDICATE_MEMBERSHIP_V6 6
typedef struct {
} pd_cddserviceproviders_abdicate_membership_V6_t;

#define PD_CALL_STAKING_BOND_V6 0
typedef struct {
    pd_LookupSource_V6_t controller;
    pd_CompactBalanceOf_t value;
    pd_RewardDestination_V6_t payee;
} pd_staking_bond_V6_t;

#define PD_CALL_STAKING_BOND_EXTRA_V6 1
typedef struct {
    pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_V6_t;

#define PD_CALL_STAKING_UNBOND_V6 2
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_unbond_V6_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V6 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V6_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V6 8
typedef struct {
    pd_LookupSource_V6_t controller;
} pd_staking_set_controller_V6_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V6 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V6_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V6 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V6_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V6 11
typedef struct {
    pd_Percent_V6_t factor;
} pd_staking_scale_validator_count_V6_t;

#define PD_CALL_STAKING_ADD_PERMISSIONED_VALIDATOR_V6 12
typedef struct {
    pd_IdentityId_V6_t identity;
    pd_Optionu32_t intended_count;
} pd_staking_add_permissioned_validator_V6_t;

#define PD_CALL_STAKING_REMOVE_PERMISSIONED_VALIDATOR_V6 13
typedef struct {
    pd_IdentityId_V6_t identity;
} pd_staking_remove_permissioned_validator_V6_t;

#define PD_CALL_STAKING_VALIDATE_CDD_EXPIRY_NOMINATORS_V6 14
typedef struct {
    pd_VecAccountId_V6_t targets;
} pd_staking_validate_cdd_expiry_nominators_V6_t;

#define PD_CALL_STAKING_SET_COMMISSION_CAP_V6 15
typedef struct {
    pd_Perbill_V6_t new_cap;
} pd_staking_set_commission_cap_V6_t;

#define PD_CALL_STAKING_SET_MIN_BOND_THRESHOLD_V6 16
typedef struct {
    pd_BalanceOf_t new_value;
} pd_staking_set_min_bond_threshold_V6_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V6 17
typedef struct {
} pd_staking_force_no_eras_V6_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V6 18
typedef struct {
} pd_staking_force_new_era_V6_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V6 19
typedef struct {
    pd_VecAccountId_V6_t validators;
} pd_staking_set_invulnerables_V6_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V6 20
typedef struct {
    pd_AccountId_V6_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V6_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V6 21
typedef struct {
} pd_staking_force_new_era_always_V6_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V6 22
typedef struct {
    pd_EraIndex_V6_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V6_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V6 23
typedef struct {
    pd_AccountId_V6_t validator_stash;
    pd_EraIndex_V6_t era;
} pd_staking_payout_stakers_V6_t;

#define PD_CALL_STAKING_REBOND_V6 24
typedef struct {
    pd_CompactBalanceOf_t value;
} pd_staking_rebond_V6_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V6 25
typedef struct {
    pd_CompactEraIndex_V6_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V6_t;

#define PD_CALL_STAKING_REAP_STASH_V6 26
typedef struct {
    pd_AccountId_V6_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V6_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_V6 27
typedef struct {
    pd_VecValidatorIndex_V6_t winners;
    pd_CompactAssignments_V6_t compact;
    pd_ElectionScore_V6_t score;
    pd_EraIndex_V6_t era;
    pd_ElectionSize_V6_t size;
} pd_staking_submit_election_solution_V6_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED_V6 28
typedef struct {
    pd_VecValidatorIndex_V6_t winners;
    pd_CompactAssignments_V6_t compact;
    pd_ElectionScore_V6_t score;
    pd_EraIndex_V6_t era;
    pd_ElectionSize_V6_t size;
} pd_staking_submit_election_solution_unsigned_V6_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_SYSTEM_V6 29
typedef struct {
    pd_AccountId_V6_t validator_stash;
    pd_EraIndex_V6_t era;
} pd_staking_payout_stakers_by_system_V6_t;

#define PD_CALL_STAKING_CHANGE_SLASHING_ALLOWED_FOR_V6 30
typedef struct {
    pd_SlashingSwitch_V6_t slashing_switch;
} pd_staking_change_slashing_allowed_for_V6_t;

#define PD_CALL_STAKING_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT_V6 31
typedef struct {
    pd_IdentityId_V6_t identity;
    pd_u32_t new_intended_count;
} pd_staking_update_permissioned_validator_intended_count_V6_t;

#define PD_CALL_FINALITYTRACKER_FINAL_HINT_V6 0
typedef struct {
    pd_CompactBlockNumber_t hint;
} pd_finalitytracker_final_hint_V6_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_V6 0
typedef struct {
    pd_EquivocationProof_V6_t equivocation_proof;
    pd_KeyOwnerProof_V6_t key_owner_proof;
} pd_grandpa_report_equivocation_V6_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED_V6 1
typedef struct {
    pd_EquivocationProof_V6_t equivocation_proof;
    pd_KeyOwnerProof_V6_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_V6_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V6 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V6_t;

#define PD_CALL_IMONLINE_HEARTBEAT_V6 0
typedef struct {
    pd_Heartbeat_t heartbeat;
    pd_Signature_V6_t _signature;
} pd_imonline_heartbeat_V6_t;

#define PD_CALL_IMONLINE_SET_SLASHING_PARAMS_V6 1
typedef struct {
    pd_OfflineSlashingParams_V6_t params;
} pd_imonline_set_slashing_params_V6_t;

#define PD_CALL_SUDO_SUDO_V6 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V6_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V6 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V6_t _weight;
} pd_sudo_sudo_unchecked_weight_V6_t;

#define PD_CALL_SUDO_SET_KEY_V6 2
typedef struct {
    pd_LookupSource_V6_t new_;
} pd_sudo_set_key_V6_t;

#define PD_CALL_SUDO_SUDO_AS_V6 3
typedef struct {
    pd_LookupSource_V6_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V6_t;

#define PD_CALL_MULTISIG_CREATE_MULTISIG_V6 0
typedef struct {
    pd_VecSignatory_V6_t signers;
    pd_u64_t sigs_required;
} pd_multisig_create_multisig_V6_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY_V6 1
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V6_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_identity_V6_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_KEY_V6 2
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V6_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_key_V6_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_IDENTITY_V6 3
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V6_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_identity_V6_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_KEY_V6 4
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V6_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_key_V6_t;

#define PD_CALL_MULTISIG_APPROVE_AS_IDENTITY_V6 5
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_identity_V6_t;

#define PD_CALL_MULTISIG_APPROVE_AS_KEY_V6 6
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_key_V6_t;

#define PD_CALL_MULTISIG_REJECT_AS_IDENTITY_V6 7
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_identity_V6_t;

#define PD_CALL_MULTISIG_REJECT_AS_KEY_V6 8
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_key_V6_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY_V6 9
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_identity_V6_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_KEY_V6 10
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_key_V6_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNER_V6 11
typedef struct {
    pd_Signatory_V6_t signer;
} pd_multisig_add_multisig_signer_V6_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNER_V6 12
typedef struct {
    pd_Signatory_V6_t signer;
} pd_multisig_remove_multisig_signer_V6_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNERS_VIA_CREATOR_V6 13
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_VecSignatory_V6_t signers;
} pd_multisig_add_multisig_signers_via_creator_V6_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR_V6 14
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_VecSignatory_V6_t signers;
} pd_multisig_remove_multisig_signers_via_creator_V6_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED_V6 15
typedef struct {
    pd_u64_t sigs_required;
} pd_multisig_change_sigs_required_V6_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_SIGNER_V6 16
typedef struct {
    pd_AccountId_V6_t multisig;
} pd_multisig_make_multisig_signer_V6_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_PRIMARY_V6 17
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_multisig_make_multisig_primary_V6_t;

#define PD_CALL_MULTISIG_EXECUTE_SCHEDULED_PROPOSAL_V6 18
typedef struct {
    pd_AccountId_V6_t multisig;
    pd_u64_t proposal_id;
    pd_IdentityId_V6_t multisig_did;
    pd_Weight_V6_t proposal_weight;
} pd_multisig_execute_scheduled_proposal_V6_t;

#define PD_CALL_CONTRACTS_UPDATE_SCHEDULE_V6 0
typedef struct {
    pd_Schedule_V6_t schedule;
} pd_contracts_update_schedule_V6_t;

#define PD_CALL_CONTRACTS_PUT_CODE_V6 1
typedef struct {
    pd_TemplateMetadata_V6_t meta_info;
    pd_BalanceOf_t instantiation_fee;
    pd_Bytes_t code;
} pd_contracts_put_code_V6_t;

#define PD_CALL_CONTRACTS_CALL_V6 2
typedef struct {
    pd_LookupSource_V6_t dest;
    pd_CompactBalanceOf_t value;
    pd_CompactGas_V6_t gas_limit;
    pd_Bytes_t data;
} pd_contracts_call_V6_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V6 3
typedef struct {
    pd_CompactBalanceOf_t endowment;
    pd_CompactGas_V6_t gas_limit;
    pd_CodeHash_V6_t code_hash;
    pd_Bytes_t data;
    pd_BalanceOf_t max_fee;
} pd_contracts_instantiate_V6_t;

#define PD_CALL_CONTRACTS_FREEZE_INSTANTIATION_V6 4
typedef struct {
    pd_CodeHash_V6_t code_hash;
} pd_contracts_freeze_instantiation_V6_t;

#define PD_CALL_CONTRACTS_UNFREEZE_INSTANTIATION_V6 5
typedef struct {
    pd_CodeHash_V6_t code_hash;
} pd_contracts_unfreeze_instantiation_V6_t;

#define PD_CALL_CONTRACTS_TRANSFER_TEMPLATE_OWNERSHIP_V6 6
typedef struct {
    pd_CodeHash_V6_t code_hash;
    pd_IdentityId_V6_t new_owner;
} pd_contracts_transfer_template_ownership_V6_t;

#define PD_CALL_CONTRACTS_CHANGE_TEMPLATE_FEES_V6 7
typedef struct {
    pd_CodeHash_V6_t code_hash;
    pd_OptionBalanceOf_t new_instantiation_fee;
    pd_OptionBalanceOf_t new_usage_fee;
} pd_contracts_change_template_fees_V6_t;

#define PD_CALL_CONTRACTS_CHANGE_TEMPLATE_META_URL_V6 8
typedef struct {
    pd_CodeHash_V6_t code_hash;
    pd_OptionMetaUrl_V6_t new_url;
} pd_contracts_change_template_meta_url_V6_t;

#define PD_CALL_TREASURY_DISBURSEMENT_V6 0
typedef struct {
    pd_VecBeneficiary_V6_t beneficiaries;
} pd_treasury_disbursement_V6_t;

#define PD_CALL_TREASURY_REIMBURSEMENT_V6 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_treasury_reimbursement_V6_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_VOTE_THRESHOLD_V6 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_polymeshcommittee_set_vote_threshold_V6_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_RELEASE_COORDINATOR_V6 1
typedef struct {
    pd_IdentityId_V6_t id;
} pd_polymeshcommittee_set_release_coordinator_V6_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_EXPIRES_AFTER_V6 2
typedef struct {
    pd_MaybeBlock_V6_t expiry;
} pd_polymeshcommittee_set_expires_after_V6_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_OR_PROPOSE_V6 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_polymeshcommittee_vote_or_propose_V6_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_V6 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V6_t index;
    pd_bool_t approve;
} pd_polymeshcommittee_vote_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V6 0
typedef struct {
    pd_MemberCount_V6_t limit;
} pd_committeemembership_set_active_members_limit_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_DISABLE_MEMBER_V6 1
typedef struct {
    pd_IdentityId_V6_t who;
    pd_OptionMoment_V6_t expiry;
    pd_OptionMoment_V6_t at;
} pd_committeemembership_disable_member_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ADD_MEMBER_V6 2
typedef struct {
    pd_IdentityId_V6_t who;
} pd_committeemembership_add_member_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_REMOVE_MEMBER_V6 3
typedef struct {
    pd_IdentityId_V6_t who;
} pd_committeemembership_remove_member_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SWAP_MEMBER_V6 4
typedef struct {
    pd_IdentityId_V6_t remove;
    pd_IdentityId_V6_t add;
} pd_committeemembership_swap_member_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_RESET_MEMBERS_V6 5
typedef struct {
    pd_VecIdentityId_V6_t members;
} pd_committeemembership_reset_members_V6_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V6 6
typedef struct {
} pd_committeemembership_abdicate_membership_V6_t;

#define PD_CALL_PIPS_SET_PRUNE_HISTORICAL_PIPS_V6 0
typedef struct {
    pd_bool_t prune;
} pd_pips_set_prune_historical_pips_V6_t;

#define PD_CALL_PIPS_SET_MIN_PROPOSAL_DEPOSIT_V6 1
typedef struct {
    pd_BalanceOf_t deposit;
} pd_pips_set_min_proposal_deposit_V6_t;

#define PD_CALL_PIPS_SET_DEFAULT_ENACTMENT_PERIOD_V6 2
typedef struct {
    pd_BlockNumber_t duration;
} pd_pips_set_default_enactment_period_V6_t;

#define PD_CALL_PIPS_SET_PENDING_PIP_EXPIRY_V6 3
typedef struct {
    pd_MaybeBlock_V6_t expiry;
} pd_pips_set_pending_pip_expiry_V6_t;

#define PD_CALL_PIPS_SET_MAX_PIP_SKIP_COUNT_V6 4
typedef struct {
    pd_SkippedCount_V6_t max;
} pd_pips_set_max_pip_skip_count_V6_t;

#define PD_CALL_PIPS_SET_ACTIVE_PIP_LIMIT_V6 5
typedef struct {
    pd_u32_t limit;
} pd_pips_set_active_pip_limit_V6_t;

#define PD_CALL_PIPS_PROPOSE_V6 6
typedef struct {
    pd_Proposal_t proposal;
    pd_BalanceOf_t deposit;
    pd_OptionUrl_V6_t url;
    pd_OptionPipDescription_V6_t description;
} pd_pips_propose_V6_t;

#define PD_CALL_PIPS_VOTE_V6 7
typedef struct {
    pd_PipId_V6_t id;
    pd_bool_t aye_or_nay;
    pd_BalanceOf_t deposit;
} pd_pips_vote_V6_t;

#define PD_CALL_PIPS_APPROVE_COMMITTEE_PROPOSAL_V6 8
typedef struct {
    pd_PipId_V6_t id;
} pd_pips_approve_committee_proposal_V6_t;

#define PD_CALL_PIPS_REJECT_PROPOSAL_V6 9
typedef struct {
    pd_PipId_V6_t id;
} pd_pips_reject_proposal_V6_t;

#define PD_CALL_PIPS_PRUNE_PROPOSAL_V6 10
typedef struct {
    pd_PipId_V6_t id;
} pd_pips_prune_proposal_V6_t;

#define PD_CALL_PIPS_RESCHEDULE_EXECUTION_V6 11
typedef struct {
    pd_PipId_V6_t id;
    pd_OptionBlockNumber_t until;
} pd_pips_reschedule_execution_V6_t;

#define PD_CALL_PIPS_CLEAR_SNAPSHOT_V6 12
typedef struct {
} pd_pips_clear_snapshot_V6_t;

#define PD_CALL_PIPS_SNAPSHOT_V6 13
typedef struct {
} pd_pips_snapshot_V6_t;

#define PD_CALL_PIPS_ENACT_SNAPSHOT_RESULTS_V6 14
typedef struct {
    pd_VecTuplePipIdSnapshotResult_V6_t results;
} pd_pips_enact_snapshot_results_V6_t;

#define PD_CALL_PIPS_EXECUTE_SCHEDULED_PIP_V6 15
typedef struct {
    pd_PipId_V6_t id;
} pd_pips_execute_scheduled_pip_V6_t;

#define PD_CALL_PIPS_EXPIRE_SCHEDULED_PIP_V6 16
typedef struct {
    pd_IdentityId_V6_t did;
    pd_PipId_V6_t id;
} pd_pips_expire_scheduled_pip_V6_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_VOTE_THRESHOLD_V6 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_technicalcommittee_set_vote_threshold_V6_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_RELEASE_COORDINATOR_V6 1
typedef struct {
    pd_IdentityId_V6_t id;
} pd_technicalcommittee_set_release_coordinator_V6_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_EXPIRES_AFTER_V6 2
typedef struct {
    pd_MaybeBlock_V6_t expiry;
} pd_technicalcommittee_set_expires_after_V6_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_OR_PROPOSE_V6 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_technicalcommittee_vote_or_propose_V6_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V6 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V6_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V6 0
typedef struct {
    pd_MemberCount_V6_t limit;
} pd_technicalcommitteemembership_set_active_members_limit_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V6 1
typedef struct {
    pd_IdentityId_V6_t who;
    pd_OptionMoment_V6_t expiry;
    pd_OptionMoment_V6_t at;
} pd_technicalcommitteemembership_disable_member_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V6 2
typedef struct {
    pd_IdentityId_V6_t who;
} pd_technicalcommitteemembership_add_member_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V6 3
typedef struct {
    pd_IdentityId_V6_t who;
} pd_technicalcommitteemembership_remove_member_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V6 4
typedef struct {
    pd_IdentityId_V6_t remove;
    pd_IdentityId_V6_t add;
} pd_technicalcommitteemembership_swap_member_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V6 5
typedef struct {
    pd_VecIdentityId_V6_t members;
} pd_technicalcommitteemembership_reset_members_V6_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V6 6
typedef struct {
} pd_technicalcommitteemembership_abdicate_membership_V6_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_VOTE_THRESHOLD_V6 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_upgradecommittee_set_vote_threshold_V6_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_RELEASE_COORDINATOR_V6 1
typedef struct {
    pd_IdentityId_V6_t id;
} pd_upgradecommittee_set_release_coordinator_V6_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_EXPIRES_AFTER_V6 2
typedef struct {
    pd_MaybeBlock_V6_t expiry;
} pd_upgradecommittee_set_expires_after_V6_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_OR_PROPOSE_V6 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_upgradecommittee_vote_or_propose_V6_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_V6 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V6_t index;
    pd_bool_t approve;
} pd_upgradecommittee_vote_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V6 0
typedef struct {
    pd_MemberCount_V6_t limit;
} pd_upgradecommitteemembership_set_active_members_limit_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V6 1
typedef struct {
    pd_IdentityId_V6_t who;
    pd_OptionMoment_V6_t expiry;
    pd_OptionMoment_V6_t at;
} pd_upgradecommitteemembership_disable_member_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ADD_MEMBER_V6 2
typedef struct {
    pd_IdentityId_V6_t who;
} pd_upgradecommitteemembership_add_member_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V6 3
typedef struct {
    pd_IdentityId_V6_t who;
} pd_upgradecommitteemembership_remove_member_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SWAP_MEMBER_V6 4
typedef struct {
    pd_IdentityId_V6_t remove;
    pd_IdentityId_V6_t add;
} pd_upgradecommitteemembership_swap_member_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_RESET_MEMBERS_V6 5
typedef struct {
    pd_VecIdentityId_V6_t members;
} pd_upgradecommitteemembership_reset_members_V6_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V6 6
typedef struct {
} pd_upgradecommitteemembership_abdicate_membership_V6_t;

#define PD_CALL_ASSET_REGISTER_TICKER_V6 0
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_asset_register_ticker_V6_t;

#define PD_CALL_ASSET_ACCEPT_TICKER_TRANSFER_V6 1
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_ticker_transfer_V6_t;

#define PD_CALL_ASSET_ACCEPT_PRIMARY_ISSUANCE_AGENT_TRANSFER_V6 2
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_primary_issuance_agent_transfer_V6_t;

#define PD_CALL_ASSET_ACCEPT_ASSET_OWNERSHIP_TRANSFER_V6 3
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_asset_ownership_transfer_V6_t;

#define PD_CALL_ASSET_CREATE_ASSET_V6 4
typedef struct {
    pd_AssetName_V6_t name;
    pd_Ticker_V6_t ticker;
    pd_BalanceNoSymbol_t total_supply;
    pd_bool_t divisible;
    pd_AssetType_V6_t asset_type;
    pd_VecAssetIdentifier_V6_t identifiers;
    pd_OptionFundingRoundName_V6_t funding_round;
} pd_asset_create_asset_V6_t;

#define PD_CALL_ASSET_FREEZE_V6 5
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_asset_freeze_V6_t;

#define PD_CALL_ASSET_UNFREEZE_V6 6
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_asset_unfreeze_V6_t;

#define PD_CALL_ASSET_RENAME_ASSET_V6 7
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_AssetName_V6_t name;
} pd_asset_rename_asset_V6_t;

#define PD_CALL_ASSET_ISSUE_V6 8
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_BalanceNoSymbol_t value;
} pd_asset_issue_V6_t;

#define PD_CALL_ASSET_REDEEM_V6 9
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_BalanceNoSymbol_t value;
} pd_asset_redeem_V6_t;

#define PD_CALL_ASSET_MAKE_DIVISIBLE_V6 10
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_asset_make_divisible_V6_t;

#define PD_CALL_ASSET_ADD_DOCUMENTS_V6 11
typedef struct {
    pd_VecDocument_V6_t docs;
    pd_Ticker_V6_t ticker;
} pd_asset_add_documents_V6_t;

#define PD_CALL_ASSET_REMOVE_DOCUMENTS_V6 12
typedef struct {
    pd_VecDocumentId_V6_t ids;
    pd_Ticker_V6_t ticker;
} pd_asset_remove_documents_V6_t;

#define PD_CALL_ASSET_SET_FUNDING_ROUND_V6 13
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_FundingRoundName_V6_t name;
} pd_asset_set_funding_round_V6_t;

#define PD_CALL_ASSET_UPDATE_IDENTIFIERS_V6 14
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_VecAssetIdentifier_V6_t identifiers;
} pd_asset_update_identifiers_V6_t;

#define PD_CALL_ASSET_ADD_EXTENSION_V6 15
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_SmartExtension_V6_t extension_details;
} pd_asset_add_extension_V6_t;

#define PD_CALL_ASSET_ARCHIVE_EXTENSION_V6 16
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_AccountId_V6_t extension_id;
} pd_asset_archive_extension_V6_t;

#define PD_CALL_ASSET_UNARCHIVE_EXTENSION_V6 17
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_AccountId_V6_t extension_id;
} pd_asset_unarchive_extension_V6_t;

#define PD_CALL_ASSET_REMOVE_PRIMARY_ISSUANCE_AGENT_V6 18
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_asset_remove_primary_issuance_agent_V6_t;

#define PD_CALL_ASSET_REMOVE_SMART_EXTENSION_V6 19
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_AccountId_V6_t extension_id;
} pd_asset_remove_smart_extension_V6_t;

#define PD_CALL_ASSET_CLAIM_CLASSIC_TICKER_V6 20
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_EcdsaSignature_V6_t ethereum_signature;
} pd_asset_claim_classic_ticker_V6_t;

#define PD_CALL_ASSET_RESERVE_CLASSIC_TICKER_V6 21
typedef struct {
    pd_ClassicTickerImport_V6_t classic_ticker_import;
    pd_IdentityId_V6_t contract_did;
    pd_TickerRegistrationConfig_V6_t config;
} pd_asset_reserve_classic_ticker_V6_t;

#define PD_CALL_BRIDGE_CHANGE_CONTROLLER_V6 0
typedef struct {
    pd_AccountId_V6_t controller;
} pd_bridge_change_controller_V6_t;

#define PD_CALL_BRIDGE_CHANGE_ADMIN_V6 1
typedef struct {
    pd_AccountId_V6_t admin;
} pd_bridge_change_admin_V6_t;

#define PD_CALL_BRIDGE_CHANGE_TIMELOCK_V6 2
typedef struct {
    pd_BlockNumber_t timelock;
} pd_bridge_change_timelock_V6_t;

#define PD_CALL_BRIDGE_FREEZE_V6 3
typedef struct {
} pd_bridge_freeze_V6_t;

#define PD_CALL_BRIDGE_UNFREEZE_V6 4
typedef struct {
} pd_bridge_unfreeze_V6_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_LIMIT_V6 5
typedef struct {
    pd_Balance_t amount;
    pd_BlockNumber_t duration;
} pd_bridge_change_bridge_limit_V6_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_EXEMPTED_V6 6
typedef struct {
    pd_VecTupleIdentityIdbool_V6_t exempted;
} pd_bridge_change_bridge_exempted_V6_t;

#define PD_CALL_BRIDGE_FORCE_HANDLE_BRIDGE_TX_V6 7
typedef struct {
    pd_BridgeTx_V6_t bridge_tx;
} pd_bridge_force_handle_bridge_tx_V6_t;

#define PD_CALL_BRIDGE_BATCH_PROPOSE_BRIDGE_TX_V6 8
typedef struct {
    pd_VecBridgeTx_V6_t bridge_txs;
} pd_bridge_batch_propose_bridge_tx_V6_t;

#define PD_CALL_BRIDGE_PROPOSE_BRIDGE_TX_V6 9
typedef struct {
    pd_BridgeTx_V6_t bridge_tx;
} pd_bridge_propose_bridge_tx_V6_t;

#define PD_CALL_BRIDGE_HANDLE_BRIDGE_TX_V6 10
typedef struct {
    pd_BridgeTx_V6_t bridge_tx;
} pd_bridge_handle_bridge_tx_V6_t;

#define PD_CALL_BRIDGE_FREEZE_TXS_V6 11
typedef struct {
    pd_VecBridgeTx_V6_t bridge_txs;
} pd_bridge_freeze_txs_V6_t;

#define PD_CALL_BRIDGE_UNFREEZE_TXS_V6 12
typedef struct {
    pd_VecBridgeTx_V6_t bridge_txs;
} pd_bridge_unfreeze_txs_V6_t;

#define PD_CALL_BRIDGE_HANDLE_SCHEDULED_BRIDGE_TX_V6 13
typedef struct {
    pd_BridgeTx_V6_t bridge_tx;
} pd_bridge_handle_scheduled_bridge_tx_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_COMPLIANCE_REQUIREMENT_V6 0
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_VecCondition_V6_t sender_conditions;
    pd_VecCondition_V6_t receiver_conditions;
} pd_compliancemanager_add_compliance_requirement_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_COMPLIANCE_REQUIREMENT_V6 1
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_u32_t id;
} pd_compliancemanager_remove_compliance_requirement_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_REPLACE_ASSET_COMPLIANCE_V6 2
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_VecComplianceRequirement_V6_t asset_compliance;
} pd_compliancemanager_replace_asset_compliance_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_RESET_ASSET_COMPLIANCE_V6 3
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_compliancemanager_reset_asset_compliance_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_PAUSE_ASSET_COMPLIANCE_V6 4
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_compliancemanager_pause_asset_compliance_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_RESUME_ASSET_COMPLIANCE_V6 5
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_compliancemanager_resume_asset_compliance_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER_V6 6
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TrustedIssuer_V6_t issuer;
} pd_compliancemanager_add_default_trusted_claim_issuer_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER_V6 7
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_IdentityId_V6_t issuer;
} pd_compliancemanager_remove_default_trusted_claim_issuer_V6_t;

#define PD_CALL_COMPLIANCEMANAGER_CHANGE_COMPLIANCE_REQUIREMENT_V6 8
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_ComplianceRequirement_V6_t new_req;
} pd_compliancemanager_change_compliance_requirement_V6_t;

#define PD_CALL_SETTLEMENT_CREATE_VENUE_V6 0
typedef struct {
    pd_VenueDetails_V6_t details;
    pd_VecAccountId_V6_t signers;
    pd_VenueType_V6_t venue_type;
} pd_settlement_create_venue_V6_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_V6 1
typedef struct {
    pd_u64_t venue_id;
    pd_OptionVenueDetails_V6_t details;
    pd_OptionVenueType_V6_t typ;
} pd_settlement_update_venue_V6_t;

#define PD_CALL_SETTLEMENT_ADD_INSTRUCTION_V6 2
typedef struct {
    pd_u64_t venue_id;
    pd_SettlementType_V6_t settlement_type;
    pd_OptionMoment_V6_t trade_date;
    pd_OptionMoment_V6_t value_date;
    pd_VecLeg_V6_t legs;
} pd_settlement_add_instruction_V6_t;

#define PD_CALL_SETTLEMENT_ADD_AND_AFFIRM_INSTRUCTION_V6 3
typedef struct {
    pd_u64_t venue_id;
    pd_SettlementType_V6_t settlement_type;
    pd_OptionMoment_V6_t trade_date;
    pd_OptionMoment_V6_t value_date;
    pd_VecLeg_V6_t legs;
    pd_VecPortfolioId_V6_t portfolios;
} pd_settlement_add_and_affirm_instruction_V6_t;

#define PD_CALL_SETTLEMENT_AFFIRM_INSTRUCTION_V6 4
typedef struct {
    pd_u64_t instruction_id;
    pd_VecPortfolioId_V6_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_affirm_instruction_V6_t;

#define PD_CALL_SETTLEMENT_WITHDRAW_AFFIRMATION_V6 5
typedef struct {
    pd_u64_t instruction_id;
    pd_VecPortfolioId_V6_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_withdraw_affirmation_V6_t;

#define PD_CALL_SETTLEMENT_REJECT_INSTRUCTION_V6 6
typedef struct {
    pd_u64_t instruction_id;
    pd_VecPortfolioId_V6_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_reject_instruction_V6_t;

#define PD_CALL_SETTLEMENT_AFFIRM_WITH_RECEIPTS_V6 7
typedef struct {
    pd_u64_t instruction_id;
    pd_VecReceiptDetails_V6_t receipt_details;
    pd_VecPortfolioId_V6_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_affirm_with_receipts_V6_t;

#define PD_CALL_SETTLEMENT_CLAIM_RECEIPT_V6 8
typedef struct {
    pd_u64_t instruction_id;
    pd_ReceiptDetails_V6_t receipt_details;
} pd_settlement_claim_receipt_V6_t;

#define PD_CALL_SETTLEMENT_UNCLAIM_RECEIPT_V6 9
typedef struct {
    pd_u64_t instruction_id;
    pd_u64_t leg_id;
} pd_settlement_unclaim_receipt_V6_t;

#define PD_CALL_SETTLEMENT_SET_VENUE_FILTERING_V6 10
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_bool_t enabled;
} pd_settlement_set_venue_filtering_V6_t;

#define PD_CALL_SETTLEMENT_ALLOW_VENUES_V6 11
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_Vecu64_t venues;
} pd_settlement_allow_venues_V6_t;

#define PD_CALL_SETTLEMENT_DISALLOW_VENUES_V6 12
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_Vecu64_t venues;
} pd_settlement_disallow_venues_V6_t;

#define PD_CALL_SETTLEMENT_EXECUTE_SCHEDULED_INSTRUCTION_V6 14
typedef struct {
    pd_u64_t instruction_id;
    pd_u32_t legs_count;
} pd_settlement_execute_scheduled_instruction_V6_t;

#define PD_CALL_STATISTICS_ADD_TRANSFER_MANAGER_V6 0
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TransferManager_V6_t new_transfer_manager;
} pd_statistics_add_transfer_manager_V6_t;

#define PD_CALL_STATISTICS_REMOVE_TRANSFER_MANAGER_V6 1
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TransferManager_V6_t transfer_manager;
} pd_statistics_remove_transfer_manager_V6_t;

#define PD_CALL_STATISTICS_ADD_EXEMPTED_ENTITIES_V6 2
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TransferManager_V6_t transfer_manager;
    pd_VecScopeId_V6_t exempted_entities;
} pd_statistics_add_exempted_entities_V6_t;

#define PD_CALL_STATISTICS_REMOVE_EXEMPTED_ENTITIES_V6 3
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TransferManager_V6_t transfer_manager;
    pd_VecScopeId_V6_t entities;
} pd_statistics_remove_exempted_entities_V6_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_COEFFICIENT_V6 0
typedef struct {
    pd_PosRatio_V6_t coefficient;
} pd_protocolfee_change_coefficient_V6_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_BASE_FEE_V6 1
typedef struct {
    pd_ProtocolOp_V6_t op;
    pd_BalanceOf_t base_fee;
} pd_protocolfee_change_base_fee_V6_t;

#define PD_CALL_UTILITY_BATCH_V6 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V6_t;

#define PD_CALL_UTILITY_BATCH_ATOMIC_V6 1
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_atomic_V6_t;

#define PD_CALL_UTILITY_BATCH_OPTIMISTIC_V6 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_optimistic_V6_t;

#define PD_CALL_UTILITY_RELAY_TX_V6 3
typedef struct {
    pd_AccountId_V6_t target;
    pd_OffChainSignature_V6_t signature;
    pd_UniqueCall_V6_t call;
} pd_utility_relay_tx_V6_t;

#define PD_CALL_PORTFOLIO_CREATE_PORTFOLIO_V6 0
typedef struct {
    pd_PortfolioName_V6_t name;
} pd_portfolio_create_portfolio_V6_t;

#define PD_CALL_PORTFOLIO_DELETE_PORTFOLIO_V6 1
typedef struct {
    pd_PortfolioNumber_V6_t num;
} pd_portfolio_delete_portfolio_V6_t;

#define PD_CALL_PORTFOLIO_MOVE_PORTFOLIO_FUNDS_V6 2
typedef struct {
    pd_PortfolioId_V6_t from;
    pd_PortfolioId_V6_t to;
    pd_VecMovePortfolioItem_V6_t items;
} pd_portfolio_move_portfolio_funds_V6_t;

#define PD_CALL_PORTFOLIO_RENAME_PORTFOLIO_V6 3
typedef struct {
    pd_PortfolioNumber_V6_t num;
    pd_PortfolioName_V6_t to_name;
} pd_portfolio_rename_portfolio_V6_t;

#define PD_CALL_SCHEDULER_SCHEDULE_V6 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionPeriod_V6_t maybe_periodic;
    pd_Priority_V6_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V6_t;

#define PD_CALL_SCHEDULER_CANCEL_V6 1
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V6_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_V6 2
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionPeriod_V6_t maybe_periodic;
    pd_Priority_V6_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V6_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED_V6 3
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V6_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER_V6 4
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionPeriod_V6_t maybe_periodic;
    pd_Priority_V6_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V6_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER_V6 5
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionPeriod_V6_t maybe_periodic;
    pd_Priority_V6_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V6_t;

#define PD_CALL_CORPORATEACTION_SET_MAX_DETAILS_LENGTH_V6 0
typedef struct {
    pd_u32_t length;
} pd_corporateaction_set_max_details_length_V6_t;

#define PD_CALL_CORPORATEACTION_RESET_CAA_V6 1
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_corporateaction_reset_caa_V6_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_TARGETS_V6 2
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_TargetIdentities_V6_t targets;
} pd_corporateaction_set_default_targets_V6_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_WITHHOLDING_TAX_V6 3
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_Tax_V6_t tax;
} pd_corporateaction_set_default_withholding_tax_V6_t;

#define PD_CALL_CORPORATEACTION_SET_DID_WITHHOLDING_TAX_V6 4
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_IdentityId_V6_t taxed_did;
    pd_OptionTax_V6_t tax;
} pd_corporateaction_set_did_withholding_tax_V6_t;

#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION_V6 5
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_CAKind_V6_t kind;
    pd_Moment_V6_t decl_date;
    pd_OptionRecordDateSpec_V6_t record_date;
    pd_CADetails_V6_t details;
    pd_OptionTargetIdentities_V6_t targets;
    pd_OptionTax_V6_t default_withholding_tax;
    pd_OptionVecTupleIdentityIdTax_V6_t withholding_tax;
} pd_corporateaction_initiate_corporate_action_V6_t;

#define PD_CALL_CORPORATEACTION_LINK_CA_DOC_V6 6
typedef struct {
    pd_CAId_V6_t id;
    pd_VecDocumentId_V6_t docs;
} pd_corporateaction_link_ca_doc_V6_t;

#define PD_CALL_CORPORATEACTION_REMOVE_CA_V6 7
typedef struct {
    pd_CAId_V6_t ca_id;
} pd_corporateaction_remove_ca_V6_t;

#define PD_CALL_CORPORATEACTION_CHANGE_RECORD_DATE_V6 8
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_OptionRecordDateSpec_V6_t record_date;
} pd_corporateaction_change_record_date_V6_t;

#define PD_CALL_CORPORATEBALLOT_ATTACH_BALLOT_V6 0
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_BallotTimeRange_V6_t range;
    pd_BallotMeta_V6_t meta;
    pd_bool_t rcv;
} pd_corporateballot_attach_ballot_V6_t;

#define PD_CALL_CORPORATEBALLOT_VOTE_V6 1
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_VecBallotVote_V6_t votes;
} pd_corporateballot_vote_V6_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_END_V6 2
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_Moment_V6_t end;
} pd_corporateballot_change_end_V6_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_META_V6 3
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_BallotMeta_V6_t meta;
} pd_corporateballot_change_meta_V6_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_RCV_V6 4
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_bool_t rcv;
} pd_corporateballot_change_rcv_V6_t;

#define PD_CALL_CORPORATEBALLOT_REMOVE_BALLOT_V6 5
typedef struct {
    pd_CAId_V6_t ca_id;
} pd_corporateballot_remove_ballot_V6_t;

#define PD_CALL_CAPITALDISTRIBUTION_DISTRIBUTE_V6 0
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_OptionPortfolioNumber_V6_t portfolio;
    pd_Ticker_V6_t currency;
    pd_Balance_t amount;
    pd_Moment_V6_t payment_at;
    pd_OptionMoment_V6_t expires_at;
} pd_capitaldistribution_distribute_V6_t;

#define PD_CALL_CAPITALDISTRIBUTION_CLAIM_V6 1
typedef struct {
    pd_CAId_V6_t ca_id;
} pd_capitaldistribution_claim_V6_t;

#define PD_CALL_CAPITALDISTRIBUTION_PUSH_BENEFIT_V6 2
typedef struct {
    pd_CAId_V6_t ca_id;
    pd_IdentityId_V6_t holder;
} pd_capitaldistribution_push_benefit_V6_t;

#define PD_CALL_CAPITALDISTRIBUTION_RECLAIM_V6 3
typedef struct {
    pd_CAId_V6_t ca_id;
} pd_capitaldistribution_reclaim_V6_t;

#define PD_CALL_CAPITALDISTRIBUTION_REMOVE_DISTRIBUTION_V6 4
typedef struct {
    pd_CAId_V6_t ca_id;
} pd_capitaldistribution_remove_distribution_V6_t;

#define PD_CALL_CHECKPOINT_CREATE_CHECKPOINT_V6 0
typedef struct {
    pd_Ticker_V6_t ticker;
} pd_checkpoint_create_checkpoint_V6_t;

#define PD_CALL_CHECKPOINT_SET_SCHEDULES_MAX_COMPLEXITY_V6 1
typedef struct {
    pd_u64_t max_complexity;
} pd_checkpoint_set_schedules_max_complexity_V6_t;

#define PD_CALL_CHECKPOINT_CREATE_SCHEDULE_V6 2
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_ScheduleSpec_V6_t schedule;
} pd_checkpoint_create_schedule_V6_t;

#define PD_CALL_CHECKPOINT_REMOVE_SCHEDULE_V6 3
typedef struct {
    pd_Ticker_V6_t ticker;
    pd_ScheduleId_V6_t id;
} pd_checkpoint_remove_schedule_V6_t;

#endif

typedef union {
    pd_balances_transfer_V6_t balances_transfer_V6;
    pd_balances_transfer_with_memo_V6_t balances_transfer_with_memo_V6;
    pd_staking_validate_V6_t staking_validate_V6;
    pd_staking_nominate_V6_t staking_nominate_V6;
    pd_staking_chill_V6_t staking_chill_V6;
    pd_staking_set_payee_V6_t staking_set_payee_V6;
    pd_session_set_keys_V6_t session_set_keys_V6;
    pd_session_purge_keys_V6_t session_purge_keys_V6;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V6_t system_fill_block_V6;
    pd_system_remark_V6_t system_remark_V6;
    pd_system_set_heap_pages_V6_t system_set_heap_pages_V6;
    pd_system_set_code_V6_t system_set_code_V6;
    pd_system_set_code_without_checks_V6_t system_set_code_without_checks_V6;
    pd_system_set_changes_trie_config_V6_t system_set_changes_trie_config_V6;
    pd_system_set_storage_V6_t system_set_storage_V6;
    pd_system_kill_storage_V6_t system_kill_storage_V6;
    pd_system_kill_prefix_V6_t system_kill_prefix_V6;
    pd_system_suicide_V6_t system_suicide_V6;
    pd_babe_report_equivocation_V6_t babe_report_equivocation_V6;
    pd_babe_report_equivocation_unsigned_V6_t babe_report_equivocation_unsigned_V6;
    pd_timestamp_set_V6_t timestamp_set_V6;
    pd_indices_claim_V6_t indices_claim_V6;
    pd_indices_transfer_V6_t indices_transfer_V6;
    pd_indices_free_V6_t indices_free_V6;
    pd_indices_force_transfer_V6_t indices_force_transfer_V6;
    pd_indices_freeze_V6_t indices_freeze_V6;
    pd_balances_deposit_block_reward_reserve_balance_V6_t balances_deposit_block_reward_reserve_balance_V6;
    pd_balances_set_balance_V6_t balances_set_balance_V6;
    pd_balances_force_transfer_V6_t balances_force_transfer_V6;
    pd_balances_burn_account_balance_V6_t balances_burn_account_balance_V6;
    pd_identity_register_did_V6_t identity_register_did_V6;
    pd_identity_cdd_register_did_V6_t identity_cdd_register_did_V6;
    pd_identity_mock_cdd_register_did_V6_t identity_mock_cdd_register_did_V6;
    pd_identity_invalidate_cdd_claims_V6_t identity_invalidate_cdd_claims_V6;
    pd_identity_remove_secondary_keys_V6_t identity_remove_secondary_keys_V6;
    pd_identity_accept_primary_key_V6_t identity_accept_primary_key_V6;
    pd_identity_change_cdd_requirement_for_mk_rotation_V6_t identity_change_cdd_requirement_for_mk_rotation_V6;
    pd_identity_join_identity_as_key_V6_t identity_join_identity_as_key_V6;
    pd_identity_join_identity_as_identity_V6_t identity_join_identity_as_identity_V6;
    pd_identity_leave_identity_as_key_V6_t identity_leave_identity_as_key_V6;
    pd_identity_leave_identity_as_identity_V6_t identity_leave_identity_as_identity_V6;
    pd_identity_add_claim_V6_t identity_add_claim_V6;
    pd_identity_forwarded_call_V6_t identity_forwarded_call_V6;
    pd_identity_revoke_claim_V6_t identity_revoke_claim_V6;
    pd_identity_set_permission_to_signer_V6_t identity_set_permission_to_signer_V6;
    pd_identity_legacy_set_permission_to_signer_V6_t identity_legacy_set_permission_to_signer_V6;
    pd_identity_freeze_secondary_keys_V6_t identity_freeze_secondary_keys_V6;
    pd_identity_unfreeze_secondary_keys_V6_t identity_unfreeze_secondary_keys_V6;
    pd_identity_get_my_did_V6_t identity_get_my_did_V6;
    pd_identity_get_cdd_of_V6_t identity_get_cdd_of_V6;
    pd_identity_add_authorization_V6_t identity_add_authorization_V6;
    pd_identity_remove_authorization_V6_t identity_remove_authorization_V6;
    pd_identity_accept_authorization_V6_t identity_accept_authorization_V6;
    pd_identity_add_secondary_keys_with_authorization_V6_t identity_add_secondary_keys_with_authorization_V6;
    pd_identity_revoke_offchain_authorization_V6_t identity_revoke_offchain_authorization_V6;
    pd_identity_add_investor_uniqueness_claim_V6_t identity_add_investor_uniqueness_claim_V6;
    pd_identity_gc_add_cdd_claim_V6_t identity_gc_add_cdd_claim_V6;
    pd_identity_gc_revoke_cdd_claim_V6_t identity_gc_revoke_cdd_claim_V6;
    pd_authorship_set_uncles_V6_t authorship_set_uncles_V6;
    pd_cddserviceproviders_set_active_members_limit_V6_t cddserviceproviders_set_active_members_limit_V6;
    pd_cddserviceproviders_disable_member_V6_t cddserviceproviders_disable_member_V6;
    pd_cddserviceproviders_add_member_V6_t cddserviceproviders_add_member_V6;
    pd_cddserviceproviders_remove_member_V6_t cddserviceproviders_remove_member_V6;
    pd_cddserviceproviders_swap_member_V6_t cddserviceproviders_swap_member_V6;
    pd_cddserviceproviders_reset_members_V6_t cddserviceproviders_reset_members_V6;
    pd_cddserviceproviders_abdicate_membership_V6_t cddserviceproviders_abdicate_membership_V6;
    pd_staking_bond_V6_t staking_bond_V6;
    pd_staking_bond_extra_V6_t staking_bond_extra_V6;
    pd_staking_unbond_V6_t staking_unbond_V6;
    pd_staking_withdraw_unbonded_V6_t staking_withdraw_unbonded_V6;
    pd_staking_set_controller_V6_t staking_set_controller_V6;
    pd_staking_set_validator_count_V6_t staking_set_validator_count_V6;
    pd_staking_increase_validator_count_V6_t staking_increase_validator_count_V6;
    pd_staking_scale_validator_count_V6_t staking_scale_validator_count_V6;
    pd_staking_add_permissioned_validator_V6_t staking_add_permissioned_validator_V6;
    pd_staking_remove_permissioned_validator_V6_t staking_remove_permissioned_validator_V6;
    pd_staking_validate_cdd_expiry_nominators_V6_t staking_validate_cdd_expiry_nominators_V6;
    pd_staking_set_commission_cap_V6_t staking_set_commission_cap_V6;
    pd_staking_set_min_bond_threshold_V6_t staking_set_min_bond_threshold_V6;
    pd_staking_force_no_eras_V6_t staking_force_no_eras_V6;
    pd_staking_force_new_era_V6_t staking_force_new_era_V6;
    pd_staking_set_invulnerables_V6_t staking_set_invulnerables_V6;
    pd_staking_force_unstake_V6_t staking_force_unstake_V6;
    pd_staking_force_new_era_always_V6_t staking_force_new_era_always_V6;
    pd_staking_cancel_deferred_slash_V6_t staking_cancel_deferred_slash_V6;
    pd_staking_payout_stakers_V6_t staking_payout_stakers_V6;
    pd_staking_rebond_V6_t staking_rebond_V6;
    pd_staking_set_history_depth_V6_t staking_set_history_depth_V6;
    pd_staking_reap_stash_V6_t staking_reap_stash_V6;
    pd_staking_submit_election_solution_V6_t staking_submit_election_solution_V6;
    pd_staking_submit_election_solution_unsigned_V6_t staking_submit_election_solution_unsigned_V6;
    pd_staking_payout_stakers_by_system_V6_t staking_payout_stakers_by_system_V6;
    pd_staking_change_slashing_allowed_for_V6_t staking_change_slashing_allowed_for_V6;
    pd_staking_update_permissioned_validator_intended_count_V6_t staking_update_permissioned_validator_intended_count_V6;
    pd_finalitytracker_final_hint_V6_t finalitytracker_final_hint_V6;
    pd_grandpa_report_equivocation_V6_t grandpa_report_equivocation_V6;
    pd_grandpa_report_equivocation_unsigned_V6_t grandpa_report_equivocation_unsigned_V6;
    pd_grandpa_note_stalled_V6_t grandpa_note_stalled_V6;
    pd_imonline_heartbeat_V6_t imonline_heartbeat_V6;
    pd_imonline_set_slashing_params_V6_t imonline_set_slashing_params_V6;
    pd_sudo_sudo_V6_t sudo_sudo_V6;
    pd_sudo_sudo_unchecked_weight_V6_t sudo_sudo_unchecked_weight_V6;
    pd_sudo_set_key_V6_t sudo_set_key_V6;
    pd_sudo_sudo_as_V6_t sudo_sudo_as_V6;
    pd_multisig_create_multisig_V6_t multisig_create_multisig_V6;
    pd_multisig_create_or_approve_proposal_as_identity_V6_t multisig_create_or_approve_proposal_as_identity_V6;
    pd_multisig_create_or_approve_proposal_as_key_V6_t multisig_create_or_approve_proposal_as_key_V6;
    pd_multisig_create_proposal_as_identity_V6_t multisig_create_proposal_as_identity_V6;
    pd_multisig_create_proposal_as_key_V6_t multisig_create_proposal_as_key_V6;
    pd_multisig_approve_as_identity_V6_t multisig_approve_as_identity_V6;
    pd_multisig_approve_as_key_V6_t multisig_approve_as_key_V6;
    pd_multisig_reject_as_identity_V6_t multisig_reject_as_identity_V6;
    pd_multisig_reject_as_key_V6_t multisig_reject_as_key_V6;
    pd_multisig_accept_multisig_signer_as_identity_V6_t multisig_accept_multisig_signer_as_identity_V6;
    pd_multisig_accept_multisig_signer_as_key_V6_t multisig_accept_multisig_signer_as_key_V6;
    pd_multisig_add_multisig_signer_V6_t multisig_add_multisig_signer_V6;
    pd_multisig_remove_multisig_signer_V6_t multisig_remove_multisig_signer_V6;
    pd_multisig_add_multisig_signers_via_creator_V6_t multisig_add_multisig_signers_via_creator_V6;
    pd_multisig_remove_multisig_signers_via_creator_V6_t multisig_remove_multisig_signers_via_creator_V6;
    pd_multisig_change_sigs_required_V6_t multisig_change_sigs_required_V6;
    pd_multisig_make_multisig_signer_V6_t multisig_make_multisig_signer_V6;
    pd_multisig_make_multisig_primary_V6_t multisig_make_multisig_primary_V6;
    pd_multisig_execute_scheduled_proposal_V6_t multisig_execute_scheduled_proposal_V6;
    pd_contracts_update_schedule_V6_t contracts_update_schedule_V6;
    pd_contracts_put_code_V6_t contracts_put_code_V6;
    pd_contracts_call_V6_t contracts_call_V6;
    pd_contracts_instantiate_V6_t contracts_instantiate_V6;
    pd_contracts_freeze_instantiation_V6_t contracts_freeze_instantiation_V6;
    pd_contracts_unfreeze_instantiation_V6_t contracts_unfreeze_instantiation_V6;
    pd_contracts_transfer_template_ownership_V6_t contracts_transfer_template_ownership_V6;
    pd_contracts_change_template_fees_V6_t contracts_change_template_fees_V6;
    pd_contracts_change_template_meta_url_V6_t contracts_change_template_meta_url_V6;
    pd_treasury_disbursement_V6_t treasury_disbursement_V6;
    pd_treasury_reimbursement_V6_t treasury_reimbursement_V6;
    pd_polymeshcommittee_set_vote_threshold_V6_t polymeshcommittee_set_vote_threshold_V6;
    pd_polymeshcommittee_set_release_coordinator_V6_t polymeshcommittee_set_release_coordinator_V6;
    pd_polymeshcommittee_set_expires_after_V6_t polymeshcommittee_set_expires_after_V6;
    pd_polymeshcommittee_vote_or_propose_V6_t polymeshcommittee_vote_or_propose_V6;
    pd_polymeshcommittee_vote_V6_t polymeshcommittee_vote_V6;
    pd_committeemembership_set_active_members_limit_V6_t committeemembership_set_active_members_limit_V6;
    pd_committeemembership_disable_member_V6_t committeemembership_disable_member_V6;
    pd_committeemembership_add_member_V6_t committeemembership_add_member_V6;
    pd_committeemembership_remove_member_V6_t committeemembership_remove_member_V6;
    pd_committeemembership_swap_member_V6_t committeemembership_swap_member_V6;
    pd_committeemembership_reset_members_V6_t committeemembership_reset_members_V6;
    pd_committeemembership_abdicate_membership_V6_t committeemembership_abdicate_membership_V6;
    pd_pips_set_prune_historical_pips_V6_t pips_set_prune_historical_pips_V6;
    pd_pips_set_min_proposal_deposit_V6_t pips_set_min_proposal_deposit_V6;
    pd_pips_set_default_enactment_period_V6_t pips_set_default_enactment_period_V6;
    pd_pips_set_pending_pip_expiry_V6_t pips_set_pending_pip_expiry_V6;
    pd_pips_set_max_pip_skip_count_V6_t pips_set_max_pip_skip_count_V6;
    pd_pips_set_active_pip_limit_V6_t pips_set_active_pip_limit_V6;
    pd_pips_propose_V6_t pips_propose_V6;
    pd_pips_vote_V6_t pips_vote_V6;
    pd_pips_approve_committee_proposal_V6_t pips_approve_committee_proposal_V6;
    pd_pips_reject_proposal_V6_t pips_reject_proposal_V6;
    pd_pips_prune_proposal_V6_t pips_prune_proposal_V6;
    pd_pips_reschedule_execution_V6_t pips_reschedule_execution_V6;
    pd_pips_clear_snapshot_V6_t pips_clear_snapshot_V6;
    pd_pips_snapshot_V6_t pips_snapshot_V6;
    pd_pips_enact_snapshot_results_V6_t pips_enact_snapshot_results_V6;
    pd_pips_execute_scheduled_pip_V6_t pips_execute_scheduled_pip_V6;
    pd_pips_expire_scheduled_pip_V6_t pips_expire_scheduled_pip_V6;
    pd_technicalcommittee_set_vote_threshold_V6_t technicalcommittee_set_vote_threshold_V6;
    pd_technicalcommittee_set_release_coordinator_V6_t technicalcommittee_set_release_coordinator_V6;
    pd_technicalcommittee_set_expires_after_V6_t technicalcommittee_set_expires_after_V6;
    pd_technicalcommittee_vote_or_propose_V6_t technicalcommittee_vote_or_propose_V6;
    pd_technicalcommittee_vote_V6_t technicalcommittee_vote_V6;
    pd_technicalcommitteemembership_set_active_members_limit_V6_t technicalcommitteemembership_set_active_members_limit_V6;
    pd_technicalcommitteemembership_disable_member_V6_t technicalcommitteemembership_disable_member_V6;
    pd_technicalcommitteemembership_add_member_V6_t technicalcommitteemembership_add_member_V6;
    pd_technicalcommitteemembership_remove_member_V6_t technicalcommitteemembership_remove_member_V6;
    pd_technicalcommitteemembership_swap_member_V6_t technicalcommitteemembership_swap_member_V6;
    pd_technicalcommitteemembership_reset_members_V6_t technicalcommitteemembership_reset_members_V6;
    pd_technicalcommitteemembership_abdicate_membership_V6_t technicalcommitteemembership_abdicate_membership_V6;
    pd_upgradecommittee_set_vote_threshold_V6_t upgradecommittee_set_vote_threshold_V6;
    pd_upgradecommittee_set_release_coordinator_V6_t upgradecommittee_set_release_coordinator_V6;
    pd_upgradecommittee_set_expires_after_V6_t upgradecommittee_set_expires_after_V6;
    pd_upgradecommittee_vote_or_propose_V6_t upgradecommittee_vote_or_propose_V6;
    pd_upgradecommittee_vote_V6_t upgradecommittee_vote_V6;
    pd_upgradecommitteemembership_set_active_members_limit_V6_t upgradecommitteemembership_set_active_members_limit_V6;
    pd_upgradecommitteemembership_disable_member_V6_t upgradecommitteemembership_disable_member_V6;
    pd_upgradecommitteemembership_add_member_V6_t upgradecommitteemembership_add_member_V6;
    pd_upgradecommitteemembership_remove_member_V6_t upgradecommitteemembership_remove_member_V6;
    pd_upgradecommitteemembership_swap_member_V6_t upgradecommitteemembership_swap_member_V6;
    pd_upgradecommitteemembership_reset_members_V6_t upgradecommitteemembership_reset_members_V6;
    pd_upgradecommitteemembership_abdicate_membership_V6_t upgradecommitteemembership_abdicate_membership_V6;
    pd_asset_register_ticker_V6_t asset_register_ticker_V6;
    pd_asset_accept_ticker_transfer_V6_t asset_accept_ticker_transfer_V6;
    pd_asset_accept_primary_issuance_agent_transfer_V6_t asset_accept_primary_issuance_agent_transfer_V6;
    pd_asset_accept_asset_ownership_transfer_V6_t asset_accept_asset_ownership_transfer_V6;
    pd_asset_create_asset_V6_t asset_create_asset_V6;
    pd_asset_freeze_V6_t asset_freeze_V6;
    pd_asset_unfreeze_V6_t asset_unfreeze_V6;
    pd_asset_rename_asset_V6_t asset_rename_asset_V6;
    pd_asset_issue_V6_t asset_issue_V6;
    pd_asset_redeem_V6_t asset_redeem_V6;
    pd_asset_make_divisible_V6_t asset_make_divisible_V6;
    pd_asset_add_documents_V6_t asset_add_documents_V6;
    pd_asset_remove_documents_V6_t asset_remove_documents_V6;
    pd_asset_set_funding_round_V6_t asset_set_funding_round_V6;
    pd_asset_update_identifiers_V6_t asset_update_identifiers_V6;
    pd_asset_add_extension_V6_t asset_add_extension_V6;
    pd_asset_archive_extension_V6_t asset_archive_extension_V6;
    pd_asset_unarchive_extension_V6_t asset_unarchive_extension_V6;
    pd_asset_remove_primary_issuance_agent_V6_t asset_remove_primary_issuance_agent_V6;
    pd_asset_remove_smart_extension_V6_t asset_remove_smart_extension_V6;
    pd_asset_claim_classic_ticker_V6_t asset_claim_classic_ticker_V6;
    pd_asset_reserve_classic_ticker_V6_t asset_reserve_classic_ticker_V6;
    pd_bridge_change_controller_V6_t bridge_change_controller_V6;
    pd_bridge_change_admin_V6_t bridge_change_admin_V6;
    pd_bridge_change_timelock_V6_t bridge_change_timelock_V6;
    pd_bridge_freeze_V6_t bridge_freeze_V6;
    pd_bridge_unfreeze_V6_t bridge_unfreeze_V6;
    pd_bridge_change_bridge_limit_V6_t bridge_change_bridge_limit_V6;
    pd_bridge_change_bridge_exempted_V6_t bridge_change_bridge_exempted_V6;
    pd_bridge_force_handle_bridge_tx_V6_t bridge_force_handle_bridge_tx_V6;
    pd_bridge_batch_propose_bridge_tx_V6_t bridge_batch_propose_bridge_tx_V6;
    pd_bridge_propose_bridge_tx_V6_t bridge_propose_bridge_tx_V6;
    pd_bridge_handle_bridge_tx_V6_t bridge_handle_bridge_tx_V6;
    pd_bridge_freeze_txs_V6_t bridge_freeze_txs_V6;
    pd_bridge_unfreeze_txs_V6_t bridge_unfreeze_txs_V6;
    pd_bridge_handle_scheduled_bridge_tx_V6_t bridge_handle_scheduled_bridge_tx_V6;
    pd_compliancemanager_add_compliance_requirement_V6_t compliancemanager_add_compliance_requirement_V6;
    pd_compliancemanager_remove_compliance_requirement_V6_t compliancemanager_remove_compliance_requirement_V6;
    pd_compliancemanager_replace_asset_compliance_V6_t compliancemanager_replace_asset_compliance_V6;
    pd_compliancemanager_reset_asset_compliance_V6_t compliancemanager_reset_asset_compliance_V6;
    pd_compliancemanager_pause_asset_compliance_V6_t compliancemanager_pause_asset_compliance_V6;
    pd_compliancemanager_resume_asset_compliance_V6_t compliancemanager_resume_asset_compliance_V6;
    pd_compliancemanager_add_default_trusted_claim_issuer_V6_t compliancemanager_add_default_trusted_claim_issuer_V6;
    pd_compliancemanager_remove_default_trusted_claim_issuer_V6_t compliancemanager_remove_default_trusted_claim_issuer_V6;
    pd_compliancemanager_change_compliance_requirement_V6_t compliancemanager_change_compliance_requirement_V6;
    pd_settlement_create_venue_V6_t settlement_create_venue_V6;
    pd_settlement_update_venue_V6_t settlement_update_venue_V6;
    pd_settlement_add_instruction_V6_t settlement_add_instruction_V6;
    pd_settlement_add_and_affirm_instruction_V6_t settlement_add_and_affirm_instruction_V6;
    pd_settlement_affirm_instruction_V6_t settlement_affirm_instruction_V6;
    pd_settlement_withdraw_affirmation_V6_t settlement_withdraw_affirmation_V6;
    pd_settlement_reject_instruction_V6_t settlement_reject_instruction_V6;
    pd_settlement_affirm_with_receipts_V6_t settlement_affirm_with_receipts_V6;
    pd_settlement_claim_receipt_V6_t settlement_claim_receipt_V6;
    pd_settlement_unclaim_receipt_V6_t settlement_unclaim_receipt_V6;
    pd_settlement_set_venue_filtering_V6_t settlement_set_venue_filtering_V6;
    pd_settlement_allow_venues_V6_t settlement_allow_venues_V6;
    pd_settlement_disallow_venues_V6_t settlement_disallow_venues_V6;
    pd_settlement_execute_scheduled_instruction_V6_t settlement_execute_scheduled_instruction_V6;
    pd_statistics_add_transfer_manager_V6_t statistics_add_transfer_manager_V6;
    pd_statistics_remove_transfer_manager_V6_t statistics_remove_transfer_manager_V6;
    pd_statistics_add_exempted_entities_V6_t statistics_add_exempted_entities_V6;
    pd_statistics_remove_exempted_entities_V6_t statistics_remove_exempted_entities_V6;
    pd_protocolfee_change_coefficient_V6_t protocolfee_change_coefficient_V6;
    pd_protocolfee_change_base_fee_V6_t protocolfee_change_base_fee_V6;
    pd_utility_batch_V6_t utility_batch_V6;
    pd_utility_batch_atomic_V6_t utility_batch_atomic_V6;
    pd_utility_batch_optimistic_V6_t utility_batch_optimistic_V6;
    pd_utility_relay_tx_V6_t utility_relay_tx_V6;
    pd_portfolio_create_portfolio_V6_t portfolio_create_portfolio_V6;
    pd_portfolio_delete_portfolio_V6_t portfolio_delete_portfolio_V6;
    pd_portfolio_move_portfolio_funds_V6_t portfolio_move_portfolio_funds_V6;
    pd_portfolio_rename_portfolio_V6_t portfolio_rename_portfolio_V6;
    pd_scheduler_schedule_V6_t scheduler_schedule_V6;
    pd_scheduler_cancel_V6_t scheduler_cancel_V6;
    pd_scheduler_schedule_named_V6_t scheduler_schedule_named_V6;
    pd_scheduler_cancel_named_V6_t scheduler_cancel_named_V6;
    pd_scheduler_schedule_after_V6_t scheduler_schedule_after_V6;
    pd_scheduler_schedule_named_after_V6_t scheduler_schedule_named_after_V6;
    pd_corporateaction_set_max_details_length_V6_t corporateaction_set_max_details_length_V6;
    pd_corporateaction_reset_caa_V6_t corporateaction_reset_caa_V6;
    pd_corporateaction_set_default_targets_V6_t corporateaction_set_default_targets_V6;
    pd_corporateaction_set_default_withholding_tax_V6_t corporateaction_set_default_withholding_tax_V6;
    pd_corporateaction_set_did_withholding_tax_V6_t corporateaction_set_did_withholding_tax_V6;
    pd_corporateaction_initiate_corporate_action_V6_t corporateaction_initiate_corporate_action_V6;
    pd_corporateaction_link_ca_doc_V6_t corporateaction_link_ca_doc_V6;
    pd_corporateaction_remove_ca_V6_t corporateaction_remove_ca_V6;
    pd_corporateaction_change_record_date_V6_t corporateaction_change_record_date_V6;
    pd_corporateballot_attach_ballot_V6_t corporateballot_attach_ballot_V6;
    pd_corporateballot_vote_V6_t corporateballot_vote_V6;
    pd_corporateballot_change_end_V6_t corporateballot_change_end_V6;
    pd_corporateballot_change_meta_V6_t corporateballot_change_meta_V6;
    pd_corporateballot_change_rcv_V6_t corporateballot_change_rcv_V6;
    pd_corporateballot_remove_ballot_V6_t corporateballot_remove_ballot_V6;
    pd_capitaldistribution_distribute_V6_t capitaldistribution_distribute_V6;
    pd_capitaldistribution_claim_V6_t capitaldistribution_claim_V6;
    pd_capitaldistribution_push_benefit_V6_t capitaldistribution_push_benefit_V6;
    pd_capitaldistribution_reclaim_V6_t capitaldistribution_reclaim_V6;
    pd_capitaldistribution_remove_distribution_V6_t capitaldistribution_remove_distribution_V6;
    pd_checkpoint_create_checkpoint_V6_t checkpoint_create_checkpoint_V6;
    pd_checkpoint_set_schedules_max_complexity_V6_t checkpoint_set_schedules_max_complexity_V6;
    pd_checkpoint_create_schedule_V6_t checkpoint_create_schedule_V6;
    pd_checkpoint_remove_schedule_V6_t checkpoint_remove_schedule_V6;
#endif
} pd_MethodNested_V6_t;

typedef union {
    pd_MethodBasic_V6_t basic;
    pd_MethodNested_V6_t nested;
} pd_Method_V6_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
