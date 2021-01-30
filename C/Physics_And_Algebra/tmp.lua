-- LOCALS

local roundLength = 30

local intermissionLength = 25

local preTime = 15

local inRound = game.ReplicatedStorage.InRound

local preRound = game.ReplicatedStorage.PreRound

local Status = game.ReplicatedStorage.Status

local gameMusic = game.Workspace.Music

local roundMusic = game.Workspace.RoundMusic

local RepStorage = game:GetService("ReplicatedStorage")

--local FadeEvent= RepStorage:WaitForChild("FadeEvent")

local Guis = game:GetService("StarterGui")

local timerDis =  Guis.Timer.Frame.TimerDisplay.Text

local Tonk = game.Workspace.Music:WaitForChild("Tonk")

local SounderService = game.SoundService

local TweenService = game:GetService("TweenService")

local Framer = Guis.Timer.Frame

local TE = game.ReplicatedStorage.TimerEvent

local TE2 = game.ReplicatedStorage.TimerEvent2



local LobbySpawn = game.Workspace.Lobby.LobbySpawn

local gameareaSpawn = game.Workspace.GameAreaSpawn



local TPort1 

local TPort2 

local TPort3 

local TPort4 

local TPort5 

local TPort6 

local TPort7 

local TPort8 

local TPort9

local TPort10

local TPort11

local TPort12

local TPort13

local TPort14

local TPort15



--local function operationPreRound()

--	game.Workspace.Music.PreRoundMusic:Play()

--end



--local music = Instance.new("Sound", game.Workspace)



local Music = Instance.new("Sound", game.Workspace)



local function playlobbyMusic(arr, count)
	
	Music:Stop()
	
	
	
	local id = arr[count]
	
	
	
	Music.SoundId = id
	
	
	
	Music:Play()
	
	
	
	
	
	
	
end



local RoundSounds = {
	
	"rbxassetid://146196311", --Luigi's Mansion
	
	"rbxassetid://730371694" --Luigi's Mansion Beta
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}





local PreSounds = {
	
	"rbxassetid://493008429", -- Metal Luigi's House
	
	"rbxassetid://141744248" -- Other Minigame Luigi's House Thing
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}









local lobbymusicTable = {
	
	"rbxassetid://5341749090", --Toontown
	
	"rbxassetid://229557311" -- Train Song
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}



local Maps = {
	
	"Blocky_MazeALPHA"
	
}



----------------------Round Functions



local function TeleportPlayer(X,Y,Z)
	
	local target = CFrame.new(X,Y,Z) 
	
	for i, player in ipairs(game.Players:GetChildren()) do
		
		--Make sure the character exists and its HumanoidRootPart exists
		
		if player.Character and player.Character:FindFirstChild("HumanoidRootPart") then
			
			--add an offset of 5 for each character
			
			player.Character.HumanoidRootPart.CFrame = target + Vector3.new(0,0,0)
			
		end
		
	end
	
end



-- God Teir function

local function PickTPortSpot(map)
	
	
	
	
	
	TPort1 = {map.TPort1.Position.X, map.TPort1.Position.Y, map.TPort1.Position.Z}
	
	TPort2 = {map.TPort2.Position.X, map.TPort2.Position.Y, map.TPort2.Position.Z}
	
	TPort3 = {map.TPort3.Position.X, map.TPort3.Position.Y, map.TPort3.Position.Z}
	
	TPort4 = {map.TPort4.Position.X, map.TPort4.Position.Y, map.TPort4.Position.Z}
	
	TPort5 = {map.TPort5.Position.X, map.TPort5.Position.Y, map.TPort5.Position.Z}
	
	TPort6 = {map.TPort6.Position.X, map.TPort6.Position.Y, map.TPort6.Position.Z}
	
	TPort7 = {map.TPort7.Position.X, map.TPort7.Position.Y, map.TPort7.Position.Z}
	
	TPort8 = {map.TPort8.Position.X, map.TPort8.Position.Y, map.TPort8.Position.Z}
	
	TPort9 = {map.TPort9.Position.X, map.TPort9.Position.Y, map.TPort9.Position.Z}
	
	TPort10 = {map.TPort10.Position.X, map.TPort10.Position.Y, map.TPort10.Position.Z}
	
	TPort11 = {map.TPort11.Position.X, map.TPort11.Position.Y, map.TPort11.Position.Z}
	
	TPort12 = {map.TPort12.Position.X, map.TPort12.Position.Y, map.TPort12.Position.Z}
	
	TPort13 = {map.TPort13.Position.X, map.TPort13.Position.Y, map.TPort13.Position.Z}
	
	TPort14 = {map.TPort14.Position.X, map.TPort14.Position.Y, map.TPort14.Position.Z}
	
	TPort15 = {map.TPort15.Position.X, map.TPort15.Position.Y, map.TPort15.Position.Z}	
	
	
	
	local player_count = game.Players:GetPlayers()
	
	local TPort_Str = "TPort"
	
	local TPort
	
	local hash_map = {}
	
	
	
	hash_map["TPort1"] = TPort1
	
	hash_map["TPort2"] = TPort2
	
	hash_map["TPort3"] = TPort3
	
	hash_map["TPort4"] = TPort4
	
	hash_map["TPort5"] = TPort5
	
	hash_map["TPort6"] = TPort6
	
	hash_map["TPort7"] = TPort7
	
	hash_map["TPort8"] = TPort8
	
	hash_map["TPort9"] = TPort9
	
	hash_map["TPort10"] = TPort10
	
	hash_map["TPort11"] = TPort11
	
	hash_map["TPort12"]	= TPort12
	
	hash_map["TPort13"] = TPort13
	
	hash_map["TPort14"]	= TPort14
	
	hash_map["TPort15"]	= TPort15
	
	
	
	for i = 1, #player_count, 1 do
		
		TPort = string.gsub(TPort_Str, 'TPort' ,'TPort'..tostring(i))
		
		local spot = hash_map[TPort]
		
		TeleportPlayer(spot[1], spot[2], spot[3])
		
	end
	
end





local function format(Int)
	
	return string.format("%02i", Int)	
	
end



local function ConvertTime(seconds)
	
	seconds = tonumber(seconds)
	
	local minutes = (seconds - seconds%60)/60
	
	seconds = seconds - minutes*60
	
	local hours = (minutes - minutes%60)/60
	
	minutes = minutes - hours*60
	
	
	
	return format(minutes)..":"..format(seconds)
	
end





local function pickMap()
	
	local map_choice = math.random(1, #Maps)
	
	round_map = Maps[map_choice]
	
	return round_map
	
end





local function chooseMap()
	
	round_map = pickMap()
	
	local ReplicatedStorage = game:GetService("ReplicatedStorage")
	
	local MapToClone = ReplicatedStorage:WaitForChild(round_map):Clone()
	
	MapToClone.Parent = game.Workspace
	
	
	
	local map
	
	if round_map == "Blocky_MazeALPHA" then
		
		map = game.Workspace.Blocky_MazeALPHA
		
	elseif round_map == "Map01" then
		
		map = game.Workspace.Map01
		
	elseif round_map == "Map02" then
		
		map = game.Workspace.Map02
		
	end
	
	
	
	
	
	return map
	
	
	
end





inRound.Changed:Connect(function()
	
	wait(1) 
	
	if inRound.Value == false then
		
		for _, player in pairs(game.Players:GetChildren()) do
			
			local char = player.Character
			
			char.HumanoidRootPart.CFrame = LobbySpawn.CFrame
			
		end
		
	end
	
end)





preRound.Changed:Connect(function()
	
	if preRound.Value == true then
		
		playlobbyMusic(PreSounds, math.random(1, #PreSounds))
		
	end
	
end)

--------------------Round Function









local function roundTimer()
	
	local benchmark = 1
	
	while wait() do
		
		inRound.Value = false
		
		preRound.Value = false
		
		-- INTERMISSION
		
		for i = intermissionLength, 0, -1 do
			
			wait(1)
			
			i = ConvertTime(i)
			
			
			
			if i == ConvertTime(intermissionLength) then  --REMEMBER THIS (SHOULD WQUAL INTERMISSION LENGTH
				
				SounderService.AmbientReverb = "NoReverb"
				
				playlobbyMusic(lobbymusicTable, math.random(1, #lobbymusicTable))
				
				
				
			end
			
			--[[

			end)

				TE.OnServerEvent:Connect(function(player)

					print("SUCC")

				end)

			]]
			
			
			
			
			
			if i > ConvertTime(benchmark) then 
				
				gameMusic.Tick:Play()
				
				
				
			elseif i == ConvertTime(benchmark) then 
				
				gameMusic.Tick:Stop()
				
				Music:Stop()
				
			end
			
			
			
			Status.Value = "Intermission: "..i..""
			
		end
		
		
		
		-- PRETIME		
		
		for i = preTime, 0, -1 do
			
			preRound.Value = true
			
			i = ConvertTime(i)
			
			if preRound.Value == true then
				
				Status.Value = "Pretime: "..i..""
				
				wait(1)
				
				--[[

				if i == ConvertTime(3) then do

						TE2.OnServerEvent:Connect(function(player)

							print("SUCC2")	

					end)

				]]
				
			end
			
		end
		
		
		
		inRound.Value = true
		
		Music:Stop() 
		
		wait(0.5) --Music Timing
		
		playlobbyMusic(RoundSounds, math.random(1, #RoundSounds))
		
		local round_map = chooseMap()
		
		print(round_map)
		
		PickTPortSpot(round_map)
		
		for i = roundLength, 0, -1 do
			
			wait(1)
			
			i = ConvertTime(i)
			
			SounderService.AmbientReverb = "Cave"
			
			Status.Value = "Game: "..i..""	 	
			
		end
		
			--[[			

			if inRound.Value == true then

				wait(1) -- ABSOLUTELY NECESSARY

				Status.Value = "Game: "..i..""

				end 

			]]
		
	end
	
end



-- Round repeat

spawn(roundTimer)