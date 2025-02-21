Scriptname REP:ReputationF4SE Native Hidden


; #### IMPORTS ####



; #### VARIABLES ####



; #### PROPERTIES ####



; #### FUNCTIONS ####
;
; description
bool Function ModFame_F4SE(String asFactionName, float afFame, bool abSilent = true, bool abDirect = true) native global


; description
bool Function ModInfamy_F4SE(String asFactionName, float afFame, bool abSilent = true, bool abDirect = true) native global


; description
float Function GetFame_F4SE(String asFactionName) native global


; description
bool Function SetFame_F4SE(String asFactionName) native global


; description
float Function GetInfamy_F4SE(String asFactionName) native global


; description
bool Function SetInfamy_F4SE(String asFactionName) native global


; description
Function SetAlignment_F4SE(String asFactionName, String asAlignment) native global


; description
Function ShowAlignment_F4SE(String asFactionName, bool abPlaySound = false, bool abShowFameInfamy = false) native global


; description
Function CheckAlignmentChange_F4SE() native global


; description
Function UpdateGeneralAlignment_F4SE(String asFactionName) native global


; description
bool Function GetFactionIndex_F4SE(String asFactionName) native global


; description
String Function GetFactionName_F4SE(int aiFactionIndex, bool abFormatted) native global


; description
String Function GetAlignment_F4SE(String asFactionName, bool abFormatted = false, bool abBracketed = false) native global


; description
String Function GetAlignmentDescription_F4SE(Strng asFactionName) native global


; description
bool Function GetActorFactionIndex_F4SE(Actor akActor) native global


; description
Function InitializeLocation_F4SE() native global


; description
Function InitializeFactionLocations_F4SE(String asFactionName) native global


; description
bool Function IsDetectedByAnyFactionMember_F4SE(Actor akSubject, String asFactionName, bool abMustHaveLOS = true) native global



; #### EVENTS ####
