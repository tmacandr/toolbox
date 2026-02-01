# Notes on Using Git Lab

## Introduction

First ... the repository is controlled via *GitLab* ... it's not (the same
as) *GitHub*.

A private database at the organization is *GitLab*

## Access

The URL path to the database server is:

```
https://gitlab.<your-server-alias-here>
```

### Quick Notes

The commands are shown for 'free' when I created a new 'Project'.

1. Git global setup
   ```
   git config --global user.name "MacAndrew, Timothy"
   git config --global user.email "<user-id>@<server-alias>
   ```

2. Create a new repository
   ```
   git clone git@gitlab.<server>/<name-of-repo>.git
   cd <name-of-repo>
   git switch --create main
   touch README.md
   git add README.md
   git commit -m "add readme"
   git push --set-upstream origin main
   ```

3. Push to an existing repository:
   ```
   cd <existing_repo>
   git remote rename origin old-origin
   git remote add origin git@gitlab<IP-addr>/<name-of-repo>
   git push --set-upstream origin --all
   git push --set-upstream origin --tags
   ```

## Settings

Some of their repositories have 'dependencies' to other repos ... kind
of like 'externals' in Subversino.

The mechanis are:
```
   (i)  Clone the repo
   (ii) Issue the following
           git submodule init
           git submodule update
        Can also do:
           git submodule update --init
```

These last two commands will bring down (i.e. sort of 'clone') the
external dependencies within the primary 'clone'.

But there are two wasy to make this work.
```
   (i) Setup the .git/config fiel to point directly
       to the URL of the dependent repos.

or

   (ii) Use SSH.
```

They chose SSH.

## SSH to Read/Write to Repositories

Which means that you have to create a public private key pair and
install the 'public' key (I think that one) in the GitLab 'Settings'
area for yoour account (i.e. in your GitLab account page).

Steps are:
```
   cd $HOME/.ssh
   vim config
      -----------------------------------------------
      Host gitlag
         Hostname gitlab.<IP-addr>
         User git
         Port 32222
         Preferredauthentications publickey
         IdentifyFile ~/.ssh/gitlab
         RequestTTY no
      -----------------------------------------------

    chmod 644 config
    cd
    ssh-keygne -t rsa -b 4096 -C "${USER}@<svr-IP-addr>" -f ~/.ssh/gitlab
    cat ~.ssh/gitlab.pub

    Copy/paste the key 'gobble-dee-gook' to:

       (a) https://gitlab.<svr-IP-addr>

           Select "M" box icon on the upper-left region

           Select "Edit Profile"

       (b) Select "SSH Keys" (left side, half-way down)

       (c) Select "Add new key" (right side)

       (d) Copy the 'gobble-dee-gook' from 'gitlab.pub' to
           the "Key" field

       (e) Give a "title"

       (f) Clear the date ... want NO expiration date.

       (g) Select "Add key" button
``` 
I guess the other half of this equation is that when you 'clone'
a repo, the config file:
```
      <your-clone>/.git/config
```
is setup to do 'pull' from submodules using SSH.  For example, for
the submodule 'libNNN', its reference is specified as:
```
   git@gitlab.<svr-IP-addr>:<proj>/<name-of-repo>/<path>/libNNN.git
```
as opposed to:
```
   https://<svr-IP-addr>:<proj>/<name-of-repo>/<path>/libNNN.git
```
I guess that's the pivot ... the "git@" means to use SSH to pull
from the repo ... and "https://" means ... well use HTTPS to
pull from the repo.

Now, all that said, there's some other mechanism that GitLab  supports
in terms of using GPG key protocol ... where:
```
   GPG := GNU Privacy Guard
```
It's a kind of reip-off of **OpenPGP** ... which is a rip-off of
**PGP** ... the old _Pretty-Good-Protection_ mechanics, etc.

But I used the **SSH** protocol ... adn never followed up on the **GPG**
protocol.  I hope this doesn't come back to bit me.

## To Create a Branch
These steps
```
   a) Log-in to GitLab

   b) Go to the specific repository to be branched.

      e.g.

      https://gitlab<svr-IP-addr>/gitlab/<proj-path>/<name-of-repo>

   c) At the (stupid "+ v" button, select the "New branch" option

   d) Enter the name of the new branch ...

   e) Select "Create branch" button.
```

## To Check-out (clone) a Branch
First ... it's not "check-out" ... it's called **clone**.
```
   a) Got to the base URL ... likely the 'develop' branch

      e.g.

      https://gitlab<svr-IP-addr>/gitlab/<proj-path>/<name-of-repo>

   b) At the pulldown option change teh selection from the
      base branch (e.g. "develop") to the new branch.

      (e.g. "Issue_43_Fix_NN_Version_Cmd")

   c) On the far right, select the "Clone v" button ...

      At the "Clone with HTTPS" option ... select the
      'clipboard' button ... this copies the URL to the
      'copy/paste' buffer.

   d) Go to a 'terminal' window:

      (i) Create and go to a new working directory

          mkdir <work-dir>

          cd <work-dir>

      (ii) Issue git 'clone' command via the just copied
           URL.

              git clone <copied-URL> -b <branch-name> <work-dir>

           For example:

              git clone https://<URL>/<path>/<repo> -b Issue_43 ./

           NOTES:
              a) The URL is (still) to the development branch.
              b) If you dont' specify the "-b <branch>" option then
                 you'll end up with a 'clone' of the main branch
                 (e.g. 'develop') anyway ... defeats the purpose
                 of making a branch.

      (iii) To verify the 'branch' was cloned, do

               git branch

            The name shown should be the name of the (just created)
            branch.

      (iv) If the branch depends on other repositories (e.g. for COTS
           libraries or other proprietary items) you need to the bring
           these items 'down' from the server's database.

           To prepare the local 'clone' to bring down other branched items,
           issue the following:

              git submodule init

           To bring the items into the local directory, issue the
           following:

              git submodule update

           For example, the repository depends on the following 'external'
           repositories:

                 project_blah
                 libstuff
                 libequations

           I'm not sure the use of the term 'external' is appropriate in
           **git** parlance.  I'm showing my penchant for **Subversion**.
```

To establish subm-module dependencies, see **Section 12** BELOW

# 5) Switch Submodule 'branch' Dependecy

Key words: Change Submodule branch dependecy
           submodule branch

I had the problem of making changes to a submodule repo
on a 'private' branch.  I then did a **commit** and **push**
frm my 'private' branch to the 'develop' branch.

But when I clone the 'parent' branch, it was referencing
the **master** branch of that submodule.

I needed to swich the submodule dependency so that the
parent 'repo' would use (i.e. 'pull') from the 'develop'
branch instead of the 'master branch.

I did the follwoing:
```
   (a) Create a private branch of the parent

   (b) Clone the PARENT private branch

       Not sure if:
         git submodule init
         git submodule update
       should be done

   (c) Then:
          cd <submodule-dir>
          git checkout develop
          git branch   # just to verify on 'develop' in submodule
          cd ..
          git status ./   # verify submodule is now 'new'
          git add <submodule-dir>
          git commit <submodule-dir>
          git push
```
After that I deleted the entire 'clone' directory and did
a fresh 'clone' ... submodule init ... update ... etc.

Then wnet to  the submodule directory and verified that the
right branch (and items) were there.

Now, all that said, I can ONLY do this on 'private' branches.
I have no privilege to do this on the 'develop' branches
and ... ergo ... the 'master branches neither.

# 6) Working in a Clone

# 7) Updating TO the Repository

# 8) Updating FROM the Repository

# 9) Merge

# 10) Difference

# 11) Delete Branch

# 12) Restore (Older) Versions

# 13) How to Create Submodule Dependency


              
