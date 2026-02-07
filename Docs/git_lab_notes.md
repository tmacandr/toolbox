# Notes on Using Git Lab

## 1) Introduction

First ... the repository is controlled via **GitLab** ... it's not (the same
as) **GitHub**.

A private database at the organization is **GitLab**

## 2) Access

The URL path to the database server is:

```
https://gitlab.<your-server-alias-here>
```

## 3) Quick Notes

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

## 4) Settings

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

## 5) SSH to Read/Write to Repositories

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

## 6) Basic Usage

Base operations are:
1. Create a working branch
2. Clone a branch for work/development

### 6.1) To Create a Branch
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

## 6.2) Clone (check-out) a Branch
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

To establish subm-module dependencies, see **Section NN** BELOW

### 6.2.1 ) Switch Submodule 'branch' Dependecy

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

I did the following:

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

### 6.3) Working in a Clone

1. The following commands will NOT update the repository
   at the server.  All this is 'prepatory' to actually doing
   an update into the server.  But changes are kept 'locally'
   in the working directory.  I believe in 'git' parlance this
   is called the 'index'.  It's like a 'local' database that
   allows 'add' and 'check-in' etc.  But none of the work goes
   into the server's (i.e. real) database ... the actual
   'repository'.  That comes later.

   You can have new files or changes to files ... and they're
   managed 'locally'.  But until you do a 'push' (see below),
   none of the 'local' history is moved into the actual
   project 'repository'.

2. Before getting started, the 'exact' definition of each of the
   following commands can be obtained via the 'help' option:
   ```
      git help
   ```
   This lists all the commands available (as opposed to 'man git').

   To get more details on a specific command, then do as follows:
   ```
      git help <command>
   ```
   For example:
   ```
      git help clone
   ```

3. **Add** - To 'add' a new new file, use:
   ```
      git add <new-file(s)>
   ```
   Your're not prompted to give a comment.  See _commit_ next.

   This 'establishes' the new file into the 'local' (ONLY!) databse
   being maintained by 'git'.

4. **commit** (Subversion _check-in_)
   First ... it's not 'check-in' ... the 'git' parlance is to 'commit'.

   To 'commit' a file:
   ```
      git commit <file(s)>
   ```
   You're now LOCALLY updating the 'history' of any changes to the
   file.  If this is the first 'commit' then this is version 1.  After
   that, any changes are tracked by doing additional 'commit' commands.

   During the 'commit', yuou will be brought to the editor to add a comment
   to describe what's going on.  Note/Atten:  the first line will act
   as the 'title' of the 'commit'.  When work items are finally moved to
   the real database (repository) this 'headline' will be shown in 'bold'
   on the web-site.  So be specific.

   After the first line then add more specifics and details as to what's
   going on.

   Which 'editory' to use can be specified in the git **config** file.  The
   mechanics of updating and maintaining the 'config' file is a science
   to itself ... ug.

5. **check-out**
   The 'check-out' mechanics in 'git' is in no way comparable to
   'check-out' in **Subversion**.  One does a **clone** adn then one does
   one or more **commit** operations.

   The 'check-out' mechanism in 'git' has something to do with the
   **merge** process from one branch to another (command-line).

6. **delete**
   In general, the command to delete is:
   ```
      git rm <file(s)>
   ```
   But to delete a directory ... and perhaps all its contents and
   sub-directories, use:
   ```
     git rm -R <file(s) or dir(s)>
   ```
   **ATTEN**:
   ```
      After the items have been deleted ... they're 'gone' ... but
      they're not actually removed from the LOCAL repository until
      you do a 'commit'.
   ```

7. General Info
   There are various commands to get the staqtus of a LOCAL repository:
   ```
      (i)   git status
      (ii)  git log
      (iii) git diff <item1> <item2>
      (iv)  git difftool <stuff1> <stuff2>
   ```
   **ATTEN**:
   ```
      You can set the 'difftool' to something like BeyondCompare via
      the 'config' file.

      I did this to 'meld' ... but then they removed 'meld' from the
      node and told me its a useless tool.  What?
   ``` 
8. **Summary**
   So ... to do CRUD the commands are:
   ```
      (i)   Create - git add <file(s)>
      (ii)  Read   - git status ... or git log
      (iii) Update - git commit <file(s)>
      (iv)  Delete - git rm <file(s)>
   ```
### 6.4) **push** Updating TO the Repository
Once you're done working and making changes the process to move the items
into the (real) database (repository) is called **push**.

So there's some 'git semantics going on here.  Local work is tracked
using **commit** ... sort of ... but not fully analogous to 'check-in'
in **Subversion**.  But he final, for-real 'update' into the repository
in the server's database/repository ... but 'git' separates this into
a two-step process ... one or more 'commit operations ... followed by
a final **push**.  Nothing gets moved into the server's repository until
a **push** is done.

To **push** changes, issue the following:
```
   git push
```
More in Section 6.6

### 6.5) Updating FROM the Repository
```
          ============================================
    Don't do the following ... use the GUI 'merge' mechanics
          ============================================
```
I think this is really a **MERGE** operation ...

To get any change that have been made to the main repository to your
LOCAL clone, do the following:
```
   cd <work-dir>    # go to the clone of the working branch
   git branch       # verify it's a working branch
   git merge origin/develop
        # This starts a 'commit'.  You're taken to the
        # commit editor ... and the title is already
        # set.  When you 'save'/'quit' the 'merege' is then
        # done ... wham!

   git status  # says the 'submodule' is modified
   
         # what does that mean?
```
To verify what happened do a _meld_ between the 'develop' directory
and your working directory.  Verify the 'merge' worked, with
no conflicts, that only the items you changed/want are now showing
as diff'd.
```
   git push
```
About 'conflicts':
```
   If a fiel you ar woking on has been changed in the repository, and
   you 'pull' from the repository, then 'git' will attempt to 'merge'
   the differences from each version of the (same) file.  If this fails,
   then 'git' marks the file as a 'conflict'.
```

### 6.6) Merge

#### 6.6.1) Merge from owner branch to owner branch - LESSON LEARNED

I don't think there's a command-line way to merge from one
branch to another ... in spite of all the verbiage I have here.

The mechanism seems to be restricted to the GitLab GUI.

Do the following:
```
   1) Go to the root repository

   2) Select "Code --> Branches" tab (on the right).

   3) Select the .
                 .
                 .
      thing on the far right of the "FROM" branch you want
      to update from.

      Then select the "Compare" option.

   4) Go to the "Target" side of the page and select the
      "TO" branch to be updated.  Don't select "MASTER" or
      "DEVELOP", etc ... these require full-up peer review.

   5) Select the "Create merge request" button ... sort of to
      the left on the page.

   6) Create the merge request:
         (a) Assign to "self"
         (b) Do NOT specify any REVIEWERs
         (c) Make sure the number of required approvals is ZERO.

   7) When the MR is created, just select "MERGE".

       voila!! Done
```

#### 6.6.2) Merge - No Conflicts (the easy way)

If there are no CONFLICGTS between the 'from' (i.e. working)
branch to the 'main' branch, then just click on the 'merge'
but in GitLab when the 'merge request' has been approved.

SEE ALSO (Section 6.6.4) notes below ...

#### 6.6.2) Merge - Conflicts (the hard way)

How to merge from a working branch to the 'main'
(or 'develop') branch where the 'main' branch has moved/changed
so there are now CONFLICTs between the two branches.

... this what I end up doing:
```
   1) If there are too many changes (i.e. CONFLICTs) from the 'trunk'
      then do the following:

      (a) Make another branch off 'develop'

      (b) clone it

          git clone <git-hash-to-repo> -b <name-of-new-branch> ./work_dir

      (c) Do 'meld' merge from the first 'work' area to this new
          'work' area.

      (d) Go to the 'develop' clone.

          ... do a 'git pull' to get the latest.

      (e) Then, do a 'meld' compare from the 'develop' clone to this
          'new' clone ...

          Verify only the 'new' work is different ... OR ... resolve
          'conflicts' in ONLY the items that are being worked.

      (f) Commit those changes.

      (g) Push those changes ... 'git push'

      (h) Redo all testing

      (i) Go to GitLab and perform a "MERGE REQUEST"

          ... verify in the 'merge request' that ONLY the files
          worked/changed are part of the request.

          ---> Go to the "Branches" button on the far left panel.

          ---> The list of all branches is shown

          ---> Click on the "New" button on the far right of the
               'branch' to be merged (to 'develop').

       (j) DELETE the 'old' work branch (<--- why?)

       (k) If the 'Merge Request' is accepted, go to GitLab

              (i)  Select teh "Mark as Ready" button

              (ii) Select the big 'green' MERGE button.

           See below ...

           There is not much to this ... the tool does the merge.

           I think select the "Close Merge Request" ... or something
           like that.

   2) ATTEN: see notes below too ... these were copied from the pop-up
             dialog when the "Merge Request" for an Issue is approved.
             There was a little hyper-link that basically said "this is
             how you do a merge using the command-line."   

```

#### 6.6.3) 'help Info from GitLab
To merge changes from one branch to another
```
   (a) Create a working directory for the 'to' branch:

       mkdir To_Branch

       cd  To_Branch

   (b) Clone

       git clone <SSH-link> ./

   (c) Merge

       git merge <from-branch>
```
Here's an example:
```
   mkdir Issue_42

   cd Issue_42

   git clone <ssh-path-to-branch> ./

   git branch     # verify branch

   git merge origin/develop

   --------------------------------
    Editor

    Enter comments

    <save> <quit>
   --------------------------------

   Result:

      "Merge made by the 'ort' strategy."

   I have no idea what that means.
```
How to UNDO an un-concluded 'merge':
```
   (i)  git reset
   (ii) git restore <file(s)>
```

#### 6.6.4) Merge - From Working Branch to 'origin/develop'

On the GitLab page for the "Merge Request", selectd the
"Mark as Ready" button.

Selct the green "Merge" button.

Oh ... I guess that's it.

... not sure what all the 'noise' below is about ...

**ATTEN** these steps were copied from the pop-up dialog when the
"Merge Request" for Issue 43 was approved.  There was a little
hyper-link that basically said "this is how you do a merge using
the command-line".

```
   Step 0:
   =======
   On the GitLab page or the "Merge Request", select the
   "Mark as Ready" button.

   Step 1:
   =======
   a) git fetch origin

   b) git checkout -b "Issue_43_Fix" "origin/Issue_43_Fix"

   Step 2:
   =======
   a) git fetch origin

   b) git checkout "develop"

   c) git merge --no-ff "Issue_43_Fix"

   Step 3
   (a) git push origin "develop"
```
See also:
```
   https://<server-IP-addr>/gitlab/help/user/project/merge_requests/
      reviewing_and_managing_merge_requests.md#
         checkout-merge-requests-locally-through-the-head-ref
```

#### 6.6.5) Merge - From One REPO to a different REPO
All the (merge) items above describe how to 'merge' from/to
branches on the SAME repository.

This is how to merge from REPO **A** to REPO **B** ... two different
repositories.

See my script 'merge_git_dirs.sh'
```
   1) Setup a new directory in clone of TO repository

      Do 'commit' of at least one item into the new
      directory.

   2) Setup/edit script 'merge_git_dirs.sh'

   3) At this point, verify that BOTH the TO and the FROM
      directories have no un-commits and that a 'push'
      from the clone areas to the repo is DONE.

   4) Run scripts

   5) 'commit' items from TO directory into branch of TO repo

      Push to branch of TO repo

      ATTEN/WARNING:  If the 'moved' items are not in the
                      location you want ... still do the
                      'push'.  Then do 'git mv'.

                      See (7) below.

   6) Do 'git rm' from FROM directory.  Do 'commit'.

      Do 'push' to (branch of) FROM repo.

      Verify items are deleted.

   7) WARNING/PROBLEMS/ISSUESs:

      (a) If the 'merge' (i.e. 'git am') fails and you want to try
          to recover and try again, you FIRST have to go into the
          TO directory's '.git' directory and delete (rm -Rf) the
          directory named 'rebase-apply'.  Otherwise, any other
          attempts to run the 'git am' will fail ... saying something
          stupid like "a rebase is already started".

      (b) If one or more files in FROM collide with TO then
          the 'git am' bombs out.

          If possible, one thing to do is edit the 'patch.txt'
          file that was generated and remove/delete the file(s)
          that collide.  For example, if a "README.md" collides
          between the FROM and the TO.  Delete the lead reference
          at the start of the 'patch.txt'.  Then look for the
          'start' of the merge/diff and delete till the next
          named merge file.

          This can get ugly if there's more than one 'merege'
          operation on each file that collides.

          The, rerun the 'git am' command:

          git am --committer-date-is-author-date < $FROM_REPO/patch.txt

          I have no idea what that "commiter-date-blah-blah"
          means.

      (c) If trying to merge to a 'new subdirectory' per step (1)
          the FROM files will go to the root of the TO
          directory.

          DO NOT ATTEMPT to 'git mv' these to the sub-directory.
          You have to 'push' the changes to the REPO.  Then
          you can do a 'git mv'.  Otherwise, you will lose all
          the 'history' that is the whole purpose of this
          rigmarole process.

          ACTUALLY - I dont' know if this matters.  When I do
                     a 'git mv' AFTER 'commit' and 'push' I
                     still LOSE the history.  ARGH!!!

                     ---> BUT NOT REALLY!?!?!?

                    What you have to do is:

                       git log --follow <file>

                    and this shows the full history of the
                    file ... even going back to the starting
                    repo.

                    Ug!  Who came up with this garbage?
```

### 6.7) Difference
Setting the 'difftool' option.

On the Linux node the IT (or maybe IA) won't allow (Linux) "Beyond Compare"
to be installed.

But they did install "meld" ... via IT request.
```
   /bin/meld
```
To set 'git' to use 'meld' instead of its default 'command-line'
diff tool, do the following IN EACH clone:
```
   cd <clone-dir>

   cd .git

   edit (vim) config

   Add the following lines:

      [diff]
              tool = meld
      [difftool]
              prompt = false
      [difftool "meld"]
              cmd = meld "$LOCAL" "$REMOTE"
```
WARNING/ATTENTION:
```
   Each 'in-dent' must be a <tab> ... not spaces (<-- I think)

   Otherwise, 'git' will silently fail to parse the
   config file for these options.

   If you are using 'vim' and have <tabs>-to-<spaces> activated,
   then even hitting <tab> won't work ... and copy/paste other
   tabs won't work.

   Do use a text editor.

   Actually, one is not supposed to 'edit' the 'config' file
   manually.  Instead, one is supposed to use the 'git' 'config'
   command to add/change the settings.
```
Even so, the options offered by the default 'git' tool is myriad.
So maybe there are features in 'git' that are not offered by 'meld'.

### 6.8) Delete Branch

Use the GitLab GUI to delete a (private) branch.
```
   (a) Got to GitLab page
   
       https://<svr-IP-addr>/<path>/<proj-name>/<name-of-REPO>
       
   (b) Select the REPOSITORY button on the far left of the page ... about
       1/4 of the way down.
       
   (c) Select teh "Branches" button that gets rendered (underneath the
       "Repository" button.
       
   (d) Carefully identify the branch you want to delete ...
   
       Verify there is a RED "Trash Can" symbol on the far right
       of the entry/line-item.
       
       Select the "Trash Can" button.
       
       Verify "Are You Sure" dialog ... can't be undone ... etc.
       
       Select OK
       
       Verify branch is gone/deleted from teh list of branches.
```

### 6.9) Restore (Older) Versions
The following:
```
   git log <file>
   
   Selete the SHA marker of the 'commit'
   
   git restore --source=<SHA-value> <file>
```
For example:
```
git restore --source=ca0397481723476128476417623ae37cd72 ./hello_world.c
```

### 6.10) How to Create Submodule Dependency
These are the steps to create a submodule dependency for a repo.

These are the specific steps done to add the 'ud-mcast' repo
as a submodule to the <repo-name> repository.

```
   cd IB_work
   
   # ATTEN:
   #    The directory 'ud-mcast' will be created by 'git'.  Do NOT create
   #    the sub-directory
   #
   #    Use SSH protocol git@gitlab<ugly-SHA-value-here>
   #    But you can use HTTP URL too, but have to provide user/password
   #
   #    Copy <ugly-SHA-value> from the GUI
   #
   git submodule add git@<ugly-SHA-value> ./src/multicast/ud-mcast <-- NO!
                                                                 <-- See below
   
   #
   # ATTEN:
   #    For a specific BRANCH use hte -b option
   #
   # ATTEN:
   #    The -b option comes BEFORE the repository name here
   #    vs teh 'clone' command where the -b option comes AFTER
   #    the repo name.
   #
   #    Yup ... 'git' consistency
   #
   #    >> AND THIS FAILED TOO !!!    <<<

   -----------------------------------------------------------
   git submodule add -b develop git@<ugly-SHA-value>
   -----------------------------------------------------------
   
   Did NOT name sub-directory.  I had to let the friggin tool
   force it, in spite of their friggin' [<path>] option.
```

Oh!  Where are you **Subversion**!!
**ATTEN**
```
   ---------------------------------------------------
   This did NOT work

   I still got the 'master' trunk and not the 'develop' branch.

   OR ... I dunno ... maybe it did work.  The .gitmodules file says
   develop.
   ---------------------------------------------------
```
**BE CAREFUL HERE**!  If you have anyting else that is not part of the
repo, theis **add** will GRAB every friggin' thing in the clone and add
it.  Then the **commit** below will blast everything into the clone
history.  Then, the **push** will permanently latch **EVERYTHING** into
the repo.

Do this a fresh clone ... **not** something where other work is being
done.
```
   git add .
```
Do a 'status' here just to make sure you're not blowing in the kitchen
sink.
```
   git status ./
```
Then:
```
   git commit -m"Describe what's going on here."

   git push
```
Not sure the following are needed in the just created submodule.  But
they have to be done for new _clone_ areas, just as is done for any
clone that has submodule dependencies:
```
   git submodule init
   git submodule update
```

