if (not(_this select 0 == "")) then {
	private "_name";
	_name = _this select 1;
	private "_uid";
	_uid = _this select 0;
	private "_player";
	_player = [_name, _uid] call anrop_aar_fnc_serializePlayer;

	private "_arr";
	_arr = ["object",
		["type", ["string", "PlayerConnected"]],
		["player", _player]
	];
	_arr call anrop_aar_fnc_sendEvent;
};