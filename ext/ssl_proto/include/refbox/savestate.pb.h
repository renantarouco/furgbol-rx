// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: savestate.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_savestate_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_savestate_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3009000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3009000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "referee.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_savestate_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_savestate_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_savestate_2eproto;
class SaveState;
class SaveStateDefaultTypeInternal;
extern SaveStateDefaultTypeInternal _SaveState_default_instance_;
class SaveState_CardInfo;
class SaveState_CardInfoDefaultTypeInternal;
extern SaveState_CardInfoDefaultTypeInternal _SaveState_CardInfo_default_instance_;
class SaveState_TimeoutInfo;
class SaveState_TimeoutInfoDefaultTypeInternal;
extern SaveState_TimeoutInfoDefaultTypeInternal _SaveState_TimeoutInfo_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::SaveState* Arena::CreateMaybeMessage<::SaveState>(Arena*);
template<> ::SaveState_CardInfo* Arena::CreateMaybeMessage<::SaveState_CardInfo>(Arena*);
template<> ::SaveState_TimeoutInfo* Arena::CreateMaybeMessage<::SaveState_TimeoutInfo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum SaveState_Team : int {
  SaveState_Team_TEAM_YELLOW = 0,
  SaveState_Team_TEAM_BLUE = 1
};
bool SaveState_Team_IsValid(int value);
constexpr SaveState_Team SaveState_Team_Team_MIN = SaveState_Team_TEAM_YELLOW;
constexpr SaveState_Team SaveState_Team_Team_MAX = SaveState_Team_TEAM_BLUE;
constexpr int SaveState_Team_Team_ARRAYSIZE = SaveState_Team_Team_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SaveState_Team_descriptor();
template<typename T>
inline const std::string& SaveState_Team_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SaveState_Team>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SaveState_Team_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    SaveState_Team_descriptor(), enum_t_value);
}
inline bool SaveState_Team_Parse(
    const std::string& name, SaveState_Team* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<SaveState_Team>(
    SaveState_Team_descriptor(), name, value);
}
enum SaveState_Card : int {
  SaveState_Card_CARD_YELLOW = 0,
  SaveState_Card_CARD_RED = 1
};
bool SaveState_Card_IsValid(int value);
constexpr SaveState_Card SaveState_Card_Card_MIN = SaveState_Card_CARD_YELLOW;
constexpr SaveState_Card SaveState_Card_Card_MAX = SaveState_Card_CARD_RED;
constexpr int SaveState_Card_Card_ARRAYSIZE = SaveState_Card_Card_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* SaveState_Card_descriptor();
template<typename T>
inline const std::string& SaveState_Card_Name(T enum_t_value) {
  static_assert(::std::is_same<T, SaveState_Card>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function SaveState_Card_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    SaveState_Card_descriptor(), enum_t_value);
}
inline bool SaveState_Card_Parse(
    const std::string& name, SaveState_Card* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<SaveState_Card>(
    SaveState_Card_descriptor(), name, value);
}
// ===================================================================

class SaveState_CardInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SaveState.CardInfo) */ {
 public:
  SaveState_CardInfo();
  virtual ~SaveState_CardInfo();

  SaveState_CardInfo(const SaveState_CardInfo& from);
  SaveState_CardInfo(SaveState_CardInfo&& from) noexcept
    : SaveState_CardInfo() {
    *this = ::std::move(from);
  }

  inline SaveState_CardInfo& operator=(const SaveState_CardInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline SaveState_CardInfo& operator=(SaveState_CardInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SaveState_CardInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SaveState_CardInfo* internal_default_instance() {
    return reinterpret_cast<const SaveState_CardInfo*>(
               &_SaveState_CardInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SaveState_CardInfo& a, SaveState_CardInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(SaveState_CardInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SaveState_CardInfo* New() const final {
    return CreateMaybeMessage<SaveState_CardInfo>(nullptr);
  }

  SaveState_CardInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SaveState_CardInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SaveState_CardInfo& from);
  void MergeFrom(const SaveState_CardInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SaveState_CardInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SaveState.CardInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_savestate_2eproto);
    return ::descriptor_table_savestate_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTeamFieldNumber = 1,
    kCardFieldNumber = 2,
  };
  // required .SaveState.Team team = 1;
  bool has_team() const;
  void clear_team();
  ::SaveState_Team team() const;
  void set_team(::SaveState_Team value);

  // required .SaveState.Card card = 2;
  bool has_card() const;
  void clear_card();
  ::SaveState_Card card() const;
  void set_card(::SaveState_Card value);

  // @@protoc_insertion_point(class_scope:SaveState.CardInfo)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int team_;
  int card_;
  friend struct ::TableStruct_savestate_2eproto;
};
// -------------------------------------------------------------------

class SaveState_TimeoutInfo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SaveState.TimeoutInfo) */ {
 public:
  SaveState_TimeoutInfo();
  virtual ~SaveState_TimeoutInfo();

  SaveState_TimeoutInfo(const SaveState_TimeoutInfo& from);
  SaveState_TimeoutInfo(SaveState_TimeoutInfo&& from) noexcept
    : SaveState_TimeoutInfo() {
    *this = ::std::move(from);
  }

  inline SaveState_TimeoutInfo& operator=(const SaveState_TimeoutInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline SaveState_TimeoutInfo& operator=(SaveState_TimeoutInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SaveState_TimeoutInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SaveState_TimeoutInfo* internal_default_instance() {
    return reinterpret_cast<const SaveState_TimeoutInfo*>(
               &_SaveState_TimeoutInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SaveState_TimeoutInfo& a, SaveState_TimeoutInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(SaveState_TimeoutInfo* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SaveState_TimeoutInfo* New() const final {
    return CreateMaybeMessage<SaveState_TimeoutInfo>(nullptr);
  }

  SaveState_TimeoutInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SaveState_TimeoutInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SaveState_TimeoutInfo& from);
  void MergeFrom(const SaveState_TimeoutInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SaveState_TimeoutInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SaveState.TimeoutInfo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_savestate_2eproto);
    return ::descriptor_table_savestate_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTeamFieldNumber = 1,
    kLeftBeforeFieldNumber = 2,
  };
  // required .SaveState.Team team = 1;
  bool has_team() const;
  void clear_team();
  ::SaveState_Team team() const;
  void set_team(::SaveState_Team value);

  // required uint32 left_before = 2;
  bool has_left_before() const;
  void clear_left_before();
  ::PROTOBUF_NAMESPACE_ID::uint32 left_before() const;
  void set_left_before(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // @@protoc_insertion_point(class_scope:SaveState.TimeoutInfo)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  int team_;
  ::PROTOBUF_NAMESPACE_ID::uint32 left_before_;
  friend struct ::TableStruct_savestate_2eproto;
};
// -------------------------------------------------------------------

class SaveState :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:SaveState) */ {
 public:
  SaveState();
  virtual ~SaveState();

  SaveState(const SaveState& from);
  SaveState(SaveState&& from) noexcept
    : SaveState() {
    *this = ::std::move(from);
  }

  inline SaveState& operator=(const SaveState& from) {
    CopyFrom(from);
    return *this;
  }
  inline SaveState& operator=(SaveState&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const SaveState& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SaveState* internal_default_instance() {
    return reinterpret_cast<const SaveState*>(
               &_SaveState_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(SaveState& a, SaveState& b) {
    a.Swap(&b);
  }
  inline void Swap(SaveState* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SaveState* New() const final {
    return CreateMaybeMessage<SaveState>(nullptr);
  }

  SaveState* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SaveState>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SaveState& from);
  void MergeFrom(const SaveState& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SaveState* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "SaveState";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_savestate_2eproto);
    return ::descriptor_table_savestate_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef SaveState_CardInfo CardInfo;
  typedef SaveState_TimeoutInfo TimeoutInfo;

  typedef SaveState_Team Team;
  static constexpr Team TEAM_YELLOW =
    SaveState_Team_TEAM_YELLOW;
  static constexpr Team TEAM_BLUE =
    SaveState_Team_TEAM_BLUE;
  static inline bool Team_IsValid(int value) {
    return SaveState_Team_IsValid(value);
  }
  static constexpr Team Team_MIN =
    SaveState_Team_Team_MIN;
  static constexpr Team Team_MAX =
    SaveState_Team_Team_MAX;
  static constexpr int Team_ARRAYSIZE =
    SaveState_Team_Team_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Team_descriptor() {
    return SaveState_Team_descriptor();
  }
  template<typename T>
  static inline const std::string& Team_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Team>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Team_Name.");
    return SaveState_Team_Name(enum_t_value);
  }
  static inline bool Team_Parse(const std::string& name,
      Team* value) {
    return SaveState_Team_Parse(name, value);
  }

  typedef SaveState_Card Card;
  static constexpr Card CARD_YELLOW =
    SaveState_Card_CARD_YELLOW;
  static constexpr Card CARD_RED =
    SaveState_Card_CARD_RED;
  static inline bool Card_IsValid(int value) {
    return SaveState_Card_IsValid(value);
  }
  static constexpr Card Card_MIN =
    SaveState_Card_Card_MIN;
  static constexpr Card Card_MAX =
    SaveState_Card_Card_MAX;
  static constexpr int Card_ARRAYSIZE =
    SaveState_Card_Card_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  Card_descriptor() {
    return SaveState_Card_descriptor();
  }
  template<typename T>
  static inline const std::string& Card_Name(T enum_t_value) {
    static_assert(::std::is_same<T, Card>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function Card_Name.");
    return SaveState_Card_Name(enum_t_value);
  }
  static inline bool Card_Parse(const std::string& name,
      Card* value) {
    return SaveState_Card_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kRefereeFieldNumber = 1,
    kLastCardFieldNumber = 5,
    kTimeoutFieldNumber = 6,
    kLastTimeoutFieldNumber = 7,
    kYellowPenaltyGoalsFieldNumber = 2,
    kBluePenaltyGoalsFieldNumber = 3,
    kTimeTakenFieldNumber = 4,
  };
  // required .SSL_Referee referee = 1;
  bool has_referee() const;
  void clear_referee();
  const ::SSL_Referee& referee() const;
  ::SSL_Referee* release_referee();
  ::SSL_Referee* mutable_referee();
  void set_allocated_referee(::SSL_Referee* referee);

  // optional .SaveState.CardInfo last_card = 5;
  bool has_last_card() const;
  void clear_last_card();
  const ::SaveState_CardInfo& last_card() const;
  ::SaveState_CardInfo* release_last_card();
  ::SaveState_CardInfo* mutable_last_card();
  void set_allocated_last_card(::SaveState_CardInfo* last_card);

  // optional .SaveState.TimeoutInfo timeout = 6;
  bool has_timeout() const;
  void clear_timeout();
  const ::SaveState_TimeoutInfo& timeout() const;
  ::SaveState_TimeoutInfo* release_timeout();
  ::SaveState_TimeoutInfo* mutable_timeout();
  void set_allocated_timeout(::SaveState_TimeoutInfo* timeout);

  // optional .SaveState.TimeoutInfo last_timeout = 7;
  bool has_last_timeout() const;
  void clear_last_timeout();
  const ::SaveState_TimeoutInfo& last_timeout() const;
  ::SaveState_TimeoutInfo* release_last_timeout();
  ::SaveState_TimeoutInfo* mutable_last_timeout();
  void set_allocated_last_timeout(::SaveState_TimeoutInfo* last_timeout);

  // required uint32 yellow_penalty_goals = 2;
  bool has_yellow_penalty_goals() const;
  void clear_yellow_penalty_goals();
  ::PROTOBUF_NAMESPACE_ID::uint32 yellow_penalty_goals() const;
  void set_yellow_penalty_goals(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // required uint32 blue_penalty_goals = 3;
  bool has_blue_penalty_goals() const;
  void clear_blue_penalty_goals();
  ::PROTOBUF_NAMESPACE_ID::uint32 blue_penalty_goals() const;
  void set_blue_penalty_goals(::PROTOBUF_NAMESPACE_ID::uint32 value);

  // required uint64 time_taken = 4;
  bool has_time_taken() const;
  void clear_time_taken();
  ::PROTOBUF_NAMESPACE_ID::uint64 time_taken() const;
  void set_time_taken(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // @@protoc_insertion_point(class_scope:SaveState)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::SSL_Referee* referee_;
  ::SaveState_CardInfo* last_card_;
  ::SaveState_TimeoutInfo* timeout_;
  ::SaveState_TimeoutInfo* last_timeout_;
  ::PROTOBUF_NAMESPACE_ID::uint32 yellow_penalty_goals_;
  ::PROTOBUF_NAMESPACE_ID::uint32 blue_penalty_goals_;
  ::PROTOBUF_NAMESPACE_ID::uint64 time_taken_;
  friend struct ::TableStruct_savestate_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SaveState_CardInfo

// required .SaveState.Team team = 1;
inline bool SaveState_CardInfo::has_team() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SaveState_CardInfo::clear_team() {
  team_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::SaveState_Team SaveState_CardInfo::team() const {
  // @@protoc_insertion_point(field_get:SaveState.CardInfo.team)
  return static_cast< ::SaveState_Team >(team_);
}
inline void SaveState_CardInfo::set_team(::SaveState_Team value) {
  assert(::SaveState_Team_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  team_ = value;
  // @@protoc_insertion_point(field_set:SaveState.CardInfo.team)
}

// required .SaveState.Card card = 2;
inline bool SaveState_CardInfo::has_card() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SaveState_CardInfo::clear_card() {
  card_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::SaveState_Card SaveState_CardInfo::card() const {
  // @@protoc_insertion_point(field_get:SaveState.CardInfo.card)
  return static_cast< ::SaveState_Card >(card_);
}
inline void SaveState_CardInfo::set_card(::SaveState_Card value) {
  assert(::SaveState_Card_IsValid(value));
  _has_bits_[0] |= 0x00000002u;
  card_ = value;
  // @@protoc_insertion_point(field_set:SaveState.CardInfo.card)
}

// -------------------------------------------------------------------

// SaveState_TimeoutInfo

// required .SaveState.Team team = 1;
inline bool SaveState_TimeoutInfo::has_team() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SaveState_TimeoutInfo::clear_team() {
  team_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::SaveState_Team SaveState_TimeoutInfo::team() const {
  // @@protoc_insertion_point(field_get:SaveState.TimeoutInfo.team)
  return static_cast< ::SaveState_Team >(team_);
}
inline void SaveState_TimeoutInfo::set_team(::SaveState_Team value) {
  assert(::SaveState_Team_IsValid(value));
  _has_bits_[0] |= 0x00000001u;
  team_ = value;
  // @@protoc_insertion_point(field_set:SaveState.TimeoutInfo.team)
}

// required uint32 left_before = 2;
inline bool SaveState_TimeoutInfo::has_left_before() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SaveState_TimeoutInfo::clear_left_before() {
  left_before_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SaveState_TimeoutInfo::left_before() const {
  // @@protoc_insertion_point(field_get:SaveState.TimeoutInfo.left_before)
  return left_before_;
}
inline void SaveState_TimeoutInfo::set_left_before(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  left_before_ = value;
  // @@protoc_insertion_point(field_set:SaveState.TimeoutInfo.left_before)
}

// -------------------------------------------------------------------

// SaveState

// required .SSL_Referee referee = 1;
inline bool SaveState::has_referee() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline const ::SSL_Referee& SaveState::referee() const {
  const ::SSL_Referee* p = referee_;
  // @@protoc_insertion_point(field_get:SaveState.referee)
  return p != nullptr ? *p : *reinterpret_cast<const ::SSL_Referee*>(
      &::_SSL_Referee_default_instance_);
}
inline ::SSL_Referee* SaveState::release_referee() {
  // @@protoc_insertion_point(field_release:SaveState.referee)
  _has_bits_[0] &= ~0x00000001u;
  ::SSL_Referee* temp = referee_;
  referee_ = nullptr;
  return temp;
}
inline ::SSL_Referee* SaveState::mutable_referee() {
  _has_bits_[0] |= 0x00000001u;
  if (referee_ == nullptr) {
    auto* p = CreateMaybeMessage<::SSL_Referee>(GetArenaNoVirtual());
    referee_ = p;
  }
  // @@protoc_insertion_point(field_mutable:SaveState.referee)
  return referee_;
}
inline void SaveState::set_allocated_referee(::SSL_Referee* referee) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(referee_);
  }
  if (referee) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      referee = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, referee, submessage_arena);
    }
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  referee_ = referee;
  // @@protoc_insertion_point(field_set_allocated:SaveState.referee)
}

// required uint32 yellow_penalty_goals = 2;
inline bool SaveState::has_yellow_penalty_goals() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SaveState::clear_yellow_penalty_goals() {
  yellow_penalty_goals_ = 0u;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SaveState::yellow_penalty_goals() const {
  // @@protoc_insertion_point(field_get:SaveState.yellow_penalty_goals)
  return yellow_penalty_goals_;
}
inline void SaveState::set_yellow_penalty_goals(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000010u;
  yellow_penalty_goals_ = value;
  // @@protoc_insertion_point(field_set:SaveState.yellow_penalty_goals)
}

// required uint32 blue_penalty_goals = 3;
inline bool SaveState::has_blue_penalty_goals() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void SaveState::clear_blue_penalty_goals() {
  blue_penalty_goals_ = 0u;
  _has_bits_[0] &= ~0x00000020u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SaveState::blue_penalty_goals() const {
  // @@protoc_insertion_point(field_get:SaveState.blue_penalty_goals)
  return blue_penalty_goals_;
}
inline void SaveState::set_blue_penalty_goals(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000020u;
  blue_penalty_goals_ = value;
  // @@protoc_insertion_point(field_set:SaveState.blue_penalty_goals)
}

// required uint64 time_taken = 4;
inline bool SaveState::has_time_taken() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void SaveState::clear_time_taken() {
  time_taken_ = PROTOBUF_ULONGLONG(0);
  _has_bits_[0] &= ~0x00000040u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 SaveState::time_taken() const {
  // @@protoc_insertion_point(field_get:SaveState.time_taken)
  return time_taken_;
}
inline void SaveState::set_time_taken(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _has_bits_[0] |= 0x00000040u;
  time_taken_ = value;
  // @@protoc_insertion_point(field_set:SaveState.time_taken)
}

// optional .SaveState.CardInfo last_card = 5;
inline bool SaveState::has_last_card() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SaveState::clear_last_card() {
  if (last_card_ != nullptr) last_card_->Clear();
  _has_bits_[0] &= ~0x00000002u;
}
inline const ::SaveState_CardInfo& SaveState::last_card() const {
  const ::SaveState_CardInfo* p = last_card_;
  // @@protoc_insertion_point(field_get:SaveState.last_card)
  return p != nullptr ? *p : *reinterpret_cast<const ::SaveState_CardInfo*>(
      &::_SaveState_CardInfo_default_instance_);
}
inline ::SaveState_CardInfo* SaveState::release_last_card() {
  // @@protoc_insertion_point(field_release:SaveState.last_card)
  _has_bits_[0] &= ~0x00000002u;
  ::SaveState_CardInfo* temp = last_card_;
  last_card_ = nullptr;
  return temp;
}
inline ::SaveState_CardInfo* SaveState::mutable_last_card() {
  _has_bits_[0] |= 0x00000002u;
  if (last_card_ == nullptr) {
    auto* p = CreateMaybeMessage<::SaveState_CardInfo>(GetArenaNoVirtual());
    last_card_ = p;
  }
  // @@protoc_insertion_point(field_mutable:SaveState.last_card)
  return last_card_;
}
inline void SaveState::set_allocated_last_card(::SaveState_CardInfo* last_card) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete last_card_;
  }
  if (last_card) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      last_card = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, last_card, submessage_arena);
    }
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  last_card_ = last_card;
  // @@protoc_insertion_point(field_set_allocated:SaveState.last_card)
}

// optional .SaveState.TimeoutInfo timeout = 6;
inline bool SaveState::has_timeout() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SaveState::clear_timeout() {
  if (timeout_ != nullptr) timeout_->Clear();
  _has_bits_[0] &= ~0x00000004u;
}
inline const ::SaveState_TimeoutInfo& SaveState::timeout() const {
  const ::SaveState_TimeoutInfo* p = timeout_;
  // @@protoc_insertion_point(field_get:SaveState.timeout)
  return p != nullptr ? *p : *reinterpret_cast<const ::SaveState_TimeoutInfo*>(
      &::_SaveState_TimeoutInfo_default_instance_);
}
inline ::SaveState_TimeoutInfo* SaveState::release_timeout() {
  // @@protoc_insertion_point(field_release:SaveState.timeout)
  _has_bits_[0] &= ~0x00000004u;
  ::SaveState_TimeoutInfo* temp = timeout_;
  timeout_ = nullptr;
  return temp;
}
inline ::SaveState_TimeoutInfo* SaveState::mutable_timeout() {
  _has_bits_[0] |= 0x00000004u;
  if (timeout_ == nullptr) {
    auto* p = CreateMaybeMessage<::SaveState_TimeoutInfo>(GetArenaNoVirtual());
    timeout_ = p;
  }
  // @@protoc_insertion_point(field_mutable:SaveState.timeout)
  return timeout_;
}
inline void SaveState::set_allocated_timeout(::SaveState_TimeoutInfo* timeout) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete timeout_;
  }
  if (timeout) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      timeout = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, timeout, submessage_arena);
    }
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  timeout_ = timeout;
  // @@protoc_insertion_point(field_set_allocated:SaveState.timeout)
}

// optional .SaveState.TimeoutInfo last_timeout = 7;
inline bool SaveState::has_last_timeout() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SaveState::clear_last_timeout() {
  if (last_timeout_ != nullptr) last_timeout_->Clear();
  _has_bits_[0] &= ~0x00000008u;
}
inline const ::SaveState_TimeoutInfo& SaveState::last_timeout() const {
  const ::SaveState_TimeoutInfo* p = last_timeout_;
  // @@protoc_insertion_point(field_get:SaveState.last_timeout)
  return p != nullptr ? *p : *reinterpret_cast<const ::SaveState_TimeoutInfo*>(
      &::_SaveState_TimeoutInfo_default_instance_);
}
inline ::SaveState_TimeoutInfo* SaveState::release_last_timeout() {
  // @@protoc_insertion_point(field_release:SaveState.last_timeout)
  _has_bits_[0] &= ~0x00000008u;
  ::SaveState_TimeoutInfo* temp = last_timeout_;
  last_timeout_ = nullptr;
  return temp;
}
inline ::SaveState_TimeoutInfo* SaveState::mutable_last_timeout() {
  _has_bits_[0] |= 0x00000008u;
  if (last_timeout_ == nullptr) {
    auto* p = CreateMaybeMessage<::SaveState_TimeoutInfo>(GetArenaNoVirtual());
    last_timeout_ = p;
  }
  // @@protoc_insertion_point(field_mutable:SaveState.last_timeout)
  return last_timeout_;
}
inline void SaveState::set_allocated_last_timeout(::SaveState_TimeoutInfo* last_timeout) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete last_timeout_;
  }
  if (last_timeout) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      last_timeout = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, last_timeout, submessage_arena);
    }
    _has_bits_[0] |= 0x00000008u;
  } else {
    _has_bits_[0] &= ~0x00000008u;
  }
  last_timeout_ = last_timeout;
  // @@protoc_insertion_point(field_set_allocated:SaveState.last_timeout)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::SaveState_Team> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SaveState_Team>() {
  return ::SaveState_Team_descriptor();
}
template <> struct is_proto_enum< ::SaveState_Card> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SaveState_Card>() {
  return ::SaveState_Card_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_savestate_2eproto