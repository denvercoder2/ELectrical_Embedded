----------------------------------------------------Main-Locals
local WS = game:GetService("Workspace")
local PLRS = game:GetService("Players")
local LIGHTING = game:GetService("Lighting")
local RF = game:GetService("ReplicatedStorage")
local RS = game:GetService("ReplicatedStorage")
local SSS = game:GetService("ServerScriptService")
local SS = game:GetService("ServerStorage")
local SG = game:GetService("StarterGui")
local SPack = game:GetService("StarterPack")
local SPlayer = game:GetService("StarterPlayer")
local SService = game:GetService("SoundService")
local Teams = game:GetService("Teams")
-----------------------------------------------------Other-Locals
local SurvivorTeam = Teams.Survivors
local ZombieTeam = Teams.Zombies
local LobbyTeam = Teams.Lobby
local timerDis = SG.MainScreenGui.Frame.TimerDisplay.Text
local Status = game.ReplicatedStorage.StringValues.Status
local Bools = RS.BoolValues
local Numbs = RS.NumbValues
local PreRoundValue = Bools.PreRound
local InRoundValue = Bools.InRound
local PostRoundValue = Bools.PostRound
local IntermissionLength = 30
local PreRoundLength = 15
local InRoundLength = 30
local PostRoundLength = 15
local MaPlayers = 0
local survivorSpawn = WS.SurvivorSpawn
local zombieSpawn = WS.ZSpawnArea:FindFirstChild("ZSpawn")
local lobbySpawn = WS.Lobby:FindFirstChild("LobbySpawn")
local eventFolder = RS:FindFirstChild("EventFolder")
local deathEvent = eventFolder.Remote.DeathEvent
local changeTeamEvent = eventFolder.Remote.ChangeEvent
local PLAYERS = game:GetService("Players")
local bodyColor = Color3.fromRGB(39, 70, 45)
local resetColor = Color3.fromRGB(255, 255, 255)
-----------------------------------------------------Modules



-----------------------------------------------------Tables


local function changeColors(player, bodyColor)
	local character = player.Character
	if not character then return end
	local bodyColors = character["Body Colors"]
	print("here")
	bodyColors.HeadColor3 = bodyColor
	bodyColors.LeftArmColor3 = bodyColor
	bodyColors.LeftLegColor3 = bodyColor
	bodyColors.RightArmColor3 = bodyColor
	bodyColors.RightLegColor3 = bodyColor
	bodyColors.TorsoColor3 = bodyColor

end
	


-----------------------------------------------------Functions

local function chooseRandomZombie()
	local PlayerTable = game:GetService("Players")
	local RandomPlayer = PlayerTable:GetPlayers()[math.random(#PlayerTable:GetPlayers())]
	local Zombie_name = RandomPlayer.Name
	RandomPlayer.Team = ZombieTeam
	return Zombie_name
end


local function assignTeams()
	local Zombie = chooseRandomZombie()
	Status.Value = "The Starting Zombie is"..Zombie
	
	for i, v in pairs(PLRS:GetChildren()) do
		if v.Team ~= ZombieTeam then
			v.Team = SurvivorTeam
		else
			v.Team = ZombieTeam
		end
	end
end

local function movePLRS()
	for _, player in pairs(PLRS:GetChildren()) do
		local char = player.Character
		if player.Team == SurvivorTeam then
			char.HumanoidRootPart.CFrame = survivorSpawn.CFrame
		elseif
			player.Team == ZombieTeam then
			char.HumanoidRootPart.CFrame = zombieSpawn.CFrame
		end
	end	
end

local function fixTeams()
	for i, v in pairs(PLRS:GetChildren()) do
		if v.Team == ZombieTeam then
			v.Team = LobbyTeam
		elseif
			v.Team == SurvivorTeam then
			v.Team = LobbyTeam
		end
	end
end

local function movePLRSBack()
	for _, player in pairs(PLRS:GetChildren()) do
		local char = player.Character
		if player.Team == SurvivorTeam then
			char.HumanoidRootPart.CFrame = lobbySpawn.CFrame
		elseif
			player.Team == ZombieTeam then
			char.HumanoidRootPart.CFrame = lobbySpawn.CFrame
		end
	end	
end

local function CountDemKids()
	local MaPlayers = 0
	for i, v in pairs(PLRS:GetChildren()) do
		MaPlayers = MaPlayers + 1
		print("Player Count: ", MaPlayers)
		Numbs.PlayersInGame.Value = MaPlayers
	end
end

local function CountDemSurvivors()
	local MaSurvivors = 0
	for i, player in ipairs(PLRS:GetChildren()) do
		if player.Team == SurvivorTeam then
			MaSurvivors = MaSurvivors + 1
			print("Survivor Count: ", MaSurvivors)
			Numbs.SurvivorsInGame.Value = MaSurvivors
		end
	end
end

local function CountDemZombies()
	local MaZombies = 0
	for i, player in pairs(PLRS:GetChildren()) do
		if player.Team == ZombieTeam then
			MaZombies = MaZombies + 1
			print("Zombie Count: ", MaZombies)
			Numbs.ZombiesInGame.Value = MaZombies
		end
	end
end

game:GetService('Players').PlayerAdded:Connect(function(player)
	player.CharacterAdded:Connect(function(character)
		character:WaitForChild('Humanoid').Died:Connect(function()
			deathEvent:FireClient(player, player.Name)
		end)	
	end)
end)

game.Players.PlayerAdded:Connect(function(plr)
	plr.CharacterRemoving:Connect(function()
		if plr.Team == SurvivorTeam then
			plr.Team = ZombieTeam
		elseif plr.Team == LobbyTeam then
			plr.Team = LobbyTeam
		end
	end)
end)

------------------------------------------------------Events



------------------------------------------------------Main

local function roundLogic()
	
	while wait() do
		for i = IntermissionLength, 0, -1 do
			PreRoundValue.Value = false
			InRoundValue.Value = false
			PostRoundValue = false
			wait(1)
			Status.Value = "Intermission: "..i..""
			CountDemKids()
			CountDemSurvivors()
			CountDemZombies()
		end
		for i = PreRoundLength, 0, -1 do
			PreRoundValue.Value = true
			InRoundValue.Value = false
			PostRoundValue = false
			wait(1)
			Status.Value = "PreRound: "..i..""
			CountDemKids()
			CountDemSurvivors()
			CountDemZombies()
		end
		assignTeams()
		movePLRS()
		for i = InRoundLength, 0, -1 do
			PreRoundValue.Value = false
			InRoundValue.Value = true
			PostRoundValue = false
			wait(1)
			Status.Value = "Round: "..i..""
			CountDemKids()
			CountDemSurvivors()
			
			for i, player in ipairs(PLRS:GetChildren()) do
				if player.Team == ZombieTeam then
					changeColors(player, bodyColor)
				end
			end			
			
			CountDemZombies()
		end
		for i = PostRoundLength, 0, -1 do
			PreRoundValue.Value = false
			InRoundValue.Value = false
			PostRoundValue = true
			wait(1)
			Status.Value = "Post: "..i..""
			CountDemKids()
			CountDemSurvivors()
			CountDemZombies()
			if i == 1 then
				
				for i, player in ipairs(PLRS:GetChildren()) do
					if player.Team == ZombieTeam then
						changeColors(player, resetColor)
					end
				end
				
				movePLRSBack()
				fixTeams()
			end
		end
	end
end

while true do
	roundLogic()
end

