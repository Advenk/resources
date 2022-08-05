# By Jeff K.
# This script takes a list and a given Active Directory username and will set all given groups to the specified user.
# The manager's username must be updated on $manager
# Needs to be pointed at a list of groups for $inputFile
# Must be a simple list of groups this script assumes there is no header

$manager = Get-ADUser -Identity "user"
$inputFile = 'C:\paths\to\list\example.csv'
$Groups = ForEach ($GroupName in $inputFile) {Get-Content $inputFile}
ForEach ($Group in $Groups){
    Set-ADGroup -Identity $Group -ManagedBy ($manager.DistinguishedName)
}
