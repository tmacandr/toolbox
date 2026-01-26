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

